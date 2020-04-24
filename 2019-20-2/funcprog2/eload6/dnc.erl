-module(dnc).
-compile(export_all).

fibs(0) ->
    1;
fibs(1) ->
    1;
fibs(N) ->
    %% fib(N-1) + fib(N-2)
    Sub1  = N-1,
    Sub2  = N-2,
    Part1 = fibs(Sub1),
    Part2 = fibs(Sub2),
    Part1 + Part2.

%% fib_par(38) = fibs(37) + fibs(36)

fib_par(N) when N < 30 ->
    fibs(N);
fib_par(N) ->
    MyPid = self(),
    spawn(fun() -> MyPid ! fibs(N-1) end),
    spawn(fun() -> MyPid ! fibs(N-2) end),
    receive
        Part1 -> 
            receive 
                Part2 -> Part1 + Part2
            end
    end.

% receive
%    P1 -> ok
% end,
% receive
%   P2 -> ok
% end,
% P1 + P2.


%% fib_par(38) = fib_par(37) + fib_par(36)
fib_par1(N) when N < 30 ->
    fibs(N);
fib_par1(N) ->
    MyPid = self(),
    spawn(fun() -> MyPid ! fib_par1(N-1) end),
    spawn(fun() -> MyPid ! fib_par1(N-2) end),
    receive
        Part1 -> 
            receive 
                Part2 -> Part1 + Part2
            end
    end.