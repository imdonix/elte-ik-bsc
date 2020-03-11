-module(first).
-export([atom/1,zero/0, add/1, inc2/1]).

atom(alma) -> ok;
atom(Alma) -> nok.

zero() -> 0.

inc2(A) -> add(A,2).

add(A) -> A + 1.

add(A, B) -> A + B.