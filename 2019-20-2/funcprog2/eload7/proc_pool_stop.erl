-module(proc_pool_stop).
-compile(export_all).

parmap(F, L) ->
    run(F, L, length(L)).

run(F, L) ->
    WorkerNum = erlang:system_info(logical_processors)*2,
    run(F, L, WorkerNum).

run(F, L, WorkerNum) ->
    Dispatcher = spawn(fun() -> dispatcher(L, WorkerNum) end),
    Collector = spawn(fun() -> collector([], length(L)) end),
    [spawn(fun() -> worker(F, Dispatcher, Collector) end) || _ <- lists:seq(1,WorkerNum)],
    Collector.

collector(Results, DataLen) ->
    receive
        {subresult, SubRes} ->
            collector([SubRes | Results], DataLen);
        {give_me, Pid} ->
            Pid ! Results,
            collector(Results, DataLen);
        {stop, Pid} when length(Results) == DataLen ->
            Pid ! Results,
            io:format("Collector terminated. Results: ~p~n", [Results]);
        {stop, Pid} ->
            Pid ! {not_ready, Results},
            collector(Results, DataLen)

    end.

dispatcher([], 0) ->
    io:format("Dispatcher terminated. ~n");
dispatcher([], WorkerNum) ->
    receive
        {done, WPid} ->
            WPid ! stop,
            dispatcher([], WorkerNum-1)
    end;
dispatcher([D1 | DTail], WorkerNum) ->
    receive
        {done, WPid} ->
            WPid ! {data, D1},
            dispatcher(DTail, WorkerNum)
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


