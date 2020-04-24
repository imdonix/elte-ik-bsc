%% self/0
%% pid/3
%% processes/0
% spawn/1, spawn/3
% !, send/2 -- asszinkron
%% flush() -- Erlng shell
% receive ... end. -- blokkol, szelektiv, feltetelnek megfelelot vesz ki, specialis FIFO

-module(processes).
-compile(export_all).

fib(0) ->
    1;
fib(1) ->
    1;
fib(N) ->
    fib(N-1) + fib(N-2).

map(F, L) ->
    [F(E) || E <- L]. 


parmap(F, L) ->
    MyPid = self(),
    [spawn(fun() -> MyPid ! F(E) end) || E <- L],
    [receive
        A -> A
     end || _ <- L].

parmap_ord(F, L) ->
    MyPid = self(),
    Pids = [spawn(fun() -> MyPid ! {self(), F(E)} end) || E <- L],
    [receive
%%        A when sender(A) == Pid  -> A -- jo lenne ezt kifejezni
        {Pid, A} -> A
     end || Pid <- Pids].


parmap_test(F, L) ->
    MyPid = self(),
    [spawn(fun() -> MyPid ! F(E) end) || E <- L],
    [receive
        ok -> "Valami nem jo";
        A -> 
            io:format("Erkezett: ~p\n", [A]),
            A
     end || _E <- L].

