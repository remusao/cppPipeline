Pipeline
========

Implementation of functional composition in C++, that is, given *n* functions of types:

```
f1 :: T1 -> T2
f2 :: T2 -> T3
...
fn :: Tn -> To
```

We want to compute the composition:

```
fn o fm o ... o f1
```

Lacking the flexible syntax of functional languges (like Haskell), we must do it with a function like this:

```
    pipeline(arg, f1, ..., fn);
```

Note that you don't have to specify any type for the template function *pipeline*.

Dependencies
------------

* A recent c++ compiler supporting c++11 *type_traits*


Usage
-----

It's really simple to use, juste include this header file into your
source file and use the *pipeline* function as stated above.
