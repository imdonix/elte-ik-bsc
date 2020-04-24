-module(ring).

-compile(export_all).

run(N) ->
    Pid = lists:foldl(fun(_, AccPid) -> 
                         NewAcc = spawn(fun() -> worker(AccPid) end),
                         NewAcc
                      end, self(), lists:seq(1, N)),
    Pid ! ok,
    receive
        ok -> vege
    end.

worker(Next) ->
    receive
        ok -> Next ! ok
    end.

%% LWP
jobb_run(N) ->  
    [First | _] = Pids = [spawn(fun() -> worker0() end) || _ <- lists:seq(1, N)], %% map %% spawn(fun worker0/0)
    share(Pids ++ [self()]), %% map
    First ! ok,
    receive
        ok -> vege
    end.

share([Pid1, Pid2 | Tail]) ->
    Pid1 ! {nextpid, Pid2},
    share([Pid2 | Tail]);
share(_) ->
    ok.

worker0() ->
    receive
        {nextpid, Next} ->
            receive
                ok -> 
                    %io:format("Megkaptam~n"), 
                    Next ! ok
            end
    end.

meg_nem_jo_run(N) ->
    [spawn(fun() -> 
            receive ok -> 
                n_Next ! ok
            end
           end) || _ <- lists:seq(1, N)]. %% [1..N]