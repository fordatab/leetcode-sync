# Split a String in Balanced Strings

**Difficulty:** Easy
**Tags:** greedy, string, counting

## Problem

Given a string containing only 'L' and 'R' characters that is already balanced (equal counts of both), partition it into the maximum number of non-empty substrings where each substring is also balanced. The string length ranges from 2 to 1000 characters.

## Approach

The solution uses a greedy approach with a running balance counter. It iterates through the string once, incrementing a counter `x` for each 'R' and decrementing it for each 'L'. Whenever the counter returns to zero, it means we've encountered equal numbers of 'R' and 'L' characters since the last balance point, forming a valid balanced substring. At each such zero-crossing, the solution increments the output counter. This greedy strategy works because splitting at the earliest possible balance point maximizes the total number of splits - delaying a split can only reduce or maintain the count, never increase it.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-15 00:52 UTC
- Runtime: 0 ms
- Memory: 7.7 MB
- Language: C++
