-module(fourth).
-compile(export_all).

%%% "alma" -> [{$a, 2}, {$l, 1}, {$m, 1}]

freq2(L) ->
    [{E, count(E, L)} || E <- L].

freq(List = [H | T]) ->
    [{H, count(H, List)} | freq(T)];
freq([]) ->
    []. 

freq3(List) ->
    freq3(List, []).

 % if guardjaban nem lehet fuggvenz hivas, csak specialis BIF hivas (is_atom, hd, tl, ....)
 %   if lists:member(H, Visited) ->
 %       freq3(T, Visited);
 %      true -> 
 %       [{H, 1 + count(H, T)} | freq3(T, [H | Visited])]
 %   end.

%% 3 listabejaras
freq3([H | T], Visited) ->
    case lists:member(H, Visited) of
        true  -> freq3(T, Visited);
        false -> [{H, 1 + count(H, T)} | freq3(T, [H | Visited])]
    end;
freq3([], _) ->
    [].

%% freq4("aalma", #{})
freq4([H | T], Map) ->
    case Map of
        #{H := C} -> freq4(T, Map#{H=>C+1});
        _ -> freq4(T, Map#{H => 1})
    end;
freq4([], Map) ->
    Map.
    %maps:to_list(Map).

%count(E, [H | T]) when E == H ->
count(E, [E | T]) ->
    1 + count(E, T);
count(E, [_ | T]) ->
    count(E, T);
count(_E, []) ->
    0.


sum(0) ->
    0;
sum(N) ->
    N + sum(N-1).

call_lambda(N) ->
    Sum = fun(0, _Fun) -> 0;
             (E, Fun) -> E + Fun(E-1, Fun)
          end,
    Sum(N, Sum).

call_lambda2(N) ->
    Sum = fun F(0) -> 0;
              F(E) -> E + F(E-1)
          end,
    Sum(N).