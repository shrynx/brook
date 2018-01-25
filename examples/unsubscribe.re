let observer =
  Observer.create(
    ~on_complete=() => Js.log("completed !"),
    ~on_error=(_err) => Js.log("woops"),
    Js.log
  );

let unsub = observer |> Observable.periodic(1000);

Js.Global.setTimeout(unsub, 5000);
