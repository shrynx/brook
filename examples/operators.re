let observer =
  Observer.create(
    ~on_complete=() => Js.log("completed !"),
    ~on_error=(_err) => Js.log("woops"),
    Js.log
  );

let is_even = (x) => x mod 2 == 0;

let announce_time = (t) => string_of_int(t) ++ " seconds have passed";

let even_seconds_observable =
  Observable.periodic(1000) |> Observable.filter(is_even) |> Observable.map(announce_time);

observer |> even_seconds_observable;
