-spec search(Nums :: [integer()], Target :: integer()) -> integer().
search(Nums, Target) ->
    search(Nums, Target, 0, length(Nums) - 1).

-spec search(Nums :: [integer()], Target :: integer(), Left :: integer(), Right :: integer()) -> integer().
search(Nums, Target, Left, Right) when Left =< Right ->
    Mid = Left + (Right - Left) div 2,
    case lists:nth(Mid + 1, Nums) of
        Target ->
            Mid;
        Value when Value < Target ->
            search(Nums, Target, Mid + 1, Right);
        Value when Value > Target ->
            search(Nums, Target, Left, Mid - 1)
    end;
search(_, _, _, _) ->
    -1.