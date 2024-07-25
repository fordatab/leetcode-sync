# Valid Parenthesis String

**Difficulty:** Medium
**Tags:** greedy, string, two-pointers, parentheses-matching

## Problem

Determine whether a string containing only parentheses and asterisks is valid, where each opening parenthesis must have a matching closing parenthesis in the correct order, and asterisks can be treated as either type of parenthesis or ignored entirely. The string can be up to 100 characters long.

## Approach

The solution uses a greedy range-tracking approach that maintains two counters representing the minimum and maximum possible number of unmatched opening parentheses at each position.

As we scan left to right, opening parentheses increase both bounds, closing parentheses decrease both bounds, and asterisks decrease the minimum (treating it as a closing or empty) while increasing the maximum (treating it as an opening). If the maximum ever goes negative, we have too many closing parentheses that cannot be matched even with optimal asterisk assignments, so we return false.

Whenever the minimum goes negative, we reset it to zero because we can always choose to treat earlier asterisks as empty strings rather than closings. At the end, we check if the minimum is zero—this ensures there exists at least one valid asterisk assignment that leaves no unmatched opening parentheses.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-25 05:07 UTC
- Runtime: 0 ms
- Memory: 7.5 MB
- Language: C++
