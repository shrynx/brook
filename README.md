**[under development]**

# 🏞️ brook

> A small stream library for using observables with reasonml.

## 🚨 Disclaimer

By no means this library provides any guarantees, as it is a project to help me or anyone who is willing to contribute, learn/explore reasonml and inner workings of observables.

## 🎯 Aim

The goal is to support a hand full of stream constructors and operators.

This library is aimed to be used only with bucklescript to generate javascript, hence won't be working for native OCaml code generation.

## ✨ Features

### ⚙️ Constructors

* list

  * [x] Observable.from_list

* promise

  * [x] Observable.from_promise

* observable

  * [ ] Observable.from_observable

* value

  * [ ] Observable.of

* periodic

  * [x] Observable.periodic

* event

  * [ ] Observable.from_event

* merge

  * [ ] Observable.merge

* combine

  * [ ] Observable.combine

* empty

  * [x] Observable.empty

* never

  * [x] Observable.never

* error

  * [x] Observable.error

### 🔧 Operators

* map

  * [x] Observable.map

* map to

  * [x] Observable.map_to

* filter

  * [x] Observable.filter

* take

  * [ ] Observable.take

* drop

  * [x] Observable.drop

* last

  * [ ] Observable.last

* append

  * [x] Observable.append

* delay

  * [ ] Observable.delay

* start with

  * [ ] Observable.start_with

* end when

  * [ ] Observable.end_when

* fold

  * [ ] Observable.fold

* flatten

  * [ ] Observable.flatten

* do

  * [ ] Observable.do
