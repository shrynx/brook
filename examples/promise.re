let observer =
  Observer.create(
    ~on_complete=() => Js.log("completed"),
    ~on_error=(_err) => Js.log("woops"),
    Js.log
  );

let async_value =
  Js.Promise.make(
    (~resolve, ~reject as _) => {
      ignore(Js.Global.setTimeout(() => [@bs] resolve(21), 2000));
      ()
    }
  );

let double = (x) => x * 2;

let promise_observable = Observable.from_promise(async_value) |> Observable.map(double);

observer |> promise_observable;
