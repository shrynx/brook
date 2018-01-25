let empty = ((on_complete, _, _)) => {
  on_complete();
  () => ()
};

let error = (e, (_, on_error, _)) => {
  on_error(e);
  () => ()
};

let never = ((_, _, _), ()) => ();

let from_list = (l: list('a), (on_complete, _, on_next)) => {
  List.iter(on_next, l);
  on_complete();
  () => ()
};

let periodic = (interval: int, (_, _, on_next)) => {
  let initial_count = ref(0);
  let update = () => {
    let value = initial_count^;
    value |> on_next;
    initial_count := value + 1
  };
  let interval_id = Js.Global.setInterval(update, interval);
  () => Js.Global.clearInterval(interval_id)
};

let map = (transform, observable, (on_complete, on_error, on_next)) => {
  let map_observer = Observer.create(~on_complete, ~on_error, (v) => transform(v) |> on_next);
  map_observer |> observable
};

let map_to = (v: 'a, observable, (on_complete, on_error, on_next)) => {
  let map_to_observer = Observer.create(~on_complete, ~on_error, (_input_value) => v |> on_next);
  map_to_observer |> observable
};

let filter = (condition, observable, (on_complete, on_error, on_next)) => {
  let filtered_observer =
    Observer.create(
      ~on_complete,
      ~on_error,
      (v) =>
        if (condition(v)) {
          v |> on_next
        }
    );
  filtered_observer |> observable
};

let drop = (count, observable, (on_complete, on_error, on_next)) => {
  let counter = ref(0);
  let drop_observer =
    Observer.create(
      ~on_complete,
      ~on_error,
      (v) => {
        counter := counter^ + 1;
        if (counter^ > count) {
          v |> on_next
        }
      }
    );
  drop_observer |> observable
};

/*
   i bet, this is the wierdest/stupidest thing you would have seen.
   attempted to write a cancelable promise abstraction, but quickly gave up on type system.
   have to fix this or convert to javascript.
 */
let from_promise = (p: Js.Promise.t('a), (on_complete, on_error, on_next)) => {
  let canceled = ref(false);
  p
  |> Js.Promise.then_(
       (value) =>
         if (canceled^) {
           Js.Promise.resolve()
         } else {
           Js.Promise.resolve(on_next(value))
         }
     )
  |> Js.Promise.then_(
       (_value) =>
         if (canceled^) {
           Js.Promise.resolve()
         } else {
           Js.Promise.resolve(on_complete())
         }
     )
  |> Js.Promise.catch(
       (_err) =>
         if (canceled^) {
           Js.Promise.resolve()
         } else {
           Js.Promise.resolve(on_error(Not_found))
         }
     )
  |> ignore;
  let cancel = () => canceled := true;
  cancel
};

let append = (o1, o2, (_, on_error, on_next) as o2_observer) => {
  let o1_observer =
    Observer.create(~on_complete=() => o2(o2_observer) |> ignore, ~on_error, on_next);
  o1(o1_observer)
};
