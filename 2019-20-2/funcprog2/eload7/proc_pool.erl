-module(proc_pool).
-compile(export_all).

parmap(F, L) ->
    run(F, L, length(L)).

run(F, L) ->
    WorkerNum = erlang:system_info(logical_processors)*2,
    run(F, L, WorkerNum).

run(F, L, WorkerNum) ->
    Dispatcher = spawn(fun() -> dispatcher(L) end),
    Collector = spawn(fun() -> collector([]) end),
    [spawn(fun() -> worker(F, Dispatcher, Collector) end) || _ <- lists:seq(1,WorkerNum)],
    Collector.

collector(Results) ->
    receive
        {subresult, SubRes} ->
            collector([SubRes | Results]);
        {give_me, Pid} ->
            Pid ! Results,
            collector(Results)
    end.

dispatcher([D1 | DTail]) ->
    receive
        {done, WPid} ->
            WPid ! {data, D1},
            dispatcher(DTail)
    end;
dispatcher([]) ->
    receive
        {done, WPid} ->
            WPid ! stop,
            dispatcher([])
    end.

worker(F, Disp, Coll) ->
    Disp ! {done, self()},
    receive
        {data, D} ->
            Coll ! {subresult, F(D)},
            %% Disp ! done,
            worker(F, Disp, Coll);
        stop ->
%            Coll ! stop,
            io:format("Worker terminated: ~p~n", [self()])
    end.


