-spec number_of_employees_who_met_target(Hours :: [integer()], Target :: integer()) -> integer().
number_of_employees_who_met_target(Hours, Target) ->
      lists:foldl(fun(EmployeeHours, Count) ->
        case EmployeeHours >= Target of
            true -> Count + 1;
            false -> Count
        end
    end, 0, Hours).
