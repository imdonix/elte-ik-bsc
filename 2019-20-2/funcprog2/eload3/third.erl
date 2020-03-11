-module(third).
-compile(export_all).

sum(0) ->
    0;
sum(N) ->
    N + sum(N-1).

call_lambda(N) ->
    Sum = fun(0, Fun) -> 0;
             (E, Fun) -> E + Fun(E-1, Fun)
          end,
    Sum(N, Sum).

prod([H|T]) ->
    H * prod(T); %% [H | fv(T) ]
prod([]) ->
    1.

fact([H|T]) ->
    [second:fact(H) | fact(T)];
fact([]) ->
    [].

fact_lc(L) ->
    {[second:fact(E) || E <- L],
     lists:map(fun second:fact/1, L),
     lists:foldr(fun(E, Acc) -> [second:fact(E) | Acc] end, [], L)}.

bool(E) when true -> E.

fact_filt(L) ->
    X = [second:fact(E) || E <- L, E > 6, E < 10],
    Y = lists:filter(fun(E) -> (E > 6) and (E < 10) end, L),
    Y = lists:filter(fun(E) -> if (E > 6) and (E < 10) -> true;
                                      not ((E > 6) and (E < 10)) -> false
                                end 
                     end, L),
    Y = lists:filter(fun(E) -> if (E > 6) and (E < 10) -> true;
                                   true -> false
                                end 
                     end, L),
    Z = lists:map(fun second:fact/1, Y),
    Z = lists:filtermap(fun(E) -> if (E > 6) and (E < 10) -> {true, second:fact(E)}; %% {true, E}
                                      true -> false
                                  end 
                        end, L),
    Z = lists:filtermap(fun(E) when (E > 6) and (E < 10) -> {true, second:fact(E)}; %% {true, E}
                           (_E) -> false %% when true
                        end, L),
    {X, Z}.

mul(A,B) ->
    A*B.

call(L) ->
    {L,
     prod(L),
     lists:foldl(fun mul/2 , 1, L),
     lists:foldl(fun(A,B) -> A*B end, 1, L),
     lists:foldl(fun erlang:'*'/2, 1, L),
     fact(L),
     lists:reverse(lists:foldl(fun(E, Acc) -> [second:fact(E) | Acc] end, [], L)), %% [second:fact(E)] ++ Acc
     lists:foldl(fun(E, Acc) -> Acc ++ [second:fact(E)] end, [], L),
     lists:foldr(fun(E, Acc) -> [second:fact(E) | Acc] end, [], L)}.

%% X = A ++ B , Nem jo: X -> A elejere ... A vegebol -> B elejere ... B vege
%% Jo: X -> A masolat elejere ... A masolat vegebol -> B elejere ... B vege
%% Z = A
%% Y = B