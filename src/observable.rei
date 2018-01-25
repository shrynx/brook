let empty: ((unit => 'a, 'b, 'c), unit) => unit;

let error: ('a, ('b, 'a => 'c, 'd), unit) => unit;

let never: (('a, 'b, 'c), unit) => unit;

let from_list: (list('a), (unit => 'b, 'c, 'a => unit), unit) => unit;

let periodic: (int, ('a, 'b, int => 'c), unit) => unit;

let map:
  ('a => 'b, ((unit => unit, exn => 'c, 'a => 'd)) => 'e, (unit => unit, exn => 'c, 'b => 'd)) =>
  'e;

let map_to:
  ('a, ((unit => unit, exn => 'b, 'c => 'd)) => 'e, (unit => unit, exn => 'b, 'a => 'd)) => 'e;

let filter:
  (
    'a => bool,
    ((unit => unit, exn => 'b, 'a => unit)) => 'c,
    (unit => unit, exn => 'b, 'a => unit)
  ) =>
  'c;

let drop:
  (int, ((unit => unit, exn => 'a, 'b => unit)) => 'c, (unit => unit, exn => 'a, 'b => unit)) => 'c;

let from_promise: (Js.Promise.t('a), (unit => unit, exn => unit, 'a => unit), unit) => unit;

let append:
  (((unit => unit, exn => 'a, 'b)) => 'c, (('d, exn => 'a, 'b)) => 'e, ('d, exn => 'a, 'b)) => 'c;