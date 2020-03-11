-module(second).
-compile(export_all).
%-export([fact/1]).


% @spec fact(integer()) -> integer()
-spec fact(non_neg_integer() | 
           [non_neg_integer()]) -> pos_integer() | 
                                   [pos_integer()].

fact(0) ->
    1;
fact(N) when is_integer(N), N > 0->
    N * fact(N-1);
    % N
    % Acc = fact(N-1)
    % Acc * N.
fact([]) ->
    [];
fact([H|T]) ->
    [fact(H) | fact(T)].
% Nem hazsnálatos startégia a totális fv definíció
%fact(_N) ->
%    "Nem jo argumentum".

fact_tail(N) -> fact_tail(N, 1).

fact_tail(0, Acc) -> 
    Acc;
fact_tail(N, Acc) ->   
    fact_tail(N-1, Acc*N).

call(L) ->
    {L, fact(L), lists:map(fun fact_tail/1, L), %% implicit fv kifejezés}. 
                 lists:map(fun(X) -> fact_tail(X) end, L)}. %% explicit fv kifejezés, lambda kifejezés