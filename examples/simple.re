let observer = Observer.create(~on_complete=() => Js.log("completed !"), Js.log);

let list = [1, 2, 3];

observer |> Observable.from_list(list);
