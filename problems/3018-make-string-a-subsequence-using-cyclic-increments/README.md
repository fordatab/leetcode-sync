# Make String a Subsequence Using Cyclic Increments

**Difficulty:** Medium
**Tags:** two-pointers, string, greedy, subsequence

## Problem

Given two strings str1 and str2, determine whether str2 can be made a subsequence of str1 by performing at most one operation. The operation allows selecting any set of character positions in str1 and incrementing each selected character cyclically (a→b, b→c, ..., z→a). The strings contain only lowercase English letters, with lengths up to 10^5.

## Approach

The solution uses a two-pointer greedy matching strategy, but with swapped inputs. It first swaps str1 and str2, then iterates through the (originally) longer string with pointer i. For each character at position i, it advances pointer j through the (originally) shorter string until finding a character that can match.

The `check` function determines if character `a` can be transformed to match character `b`. It returns true if: (1) the characters are equal (difference is 0), (2) `a` incremented by one equals `b` (difference is 1), or (3) `a` is 'z' and `b` is 'a' (difference is -25, representing the cyclic wrap-around).

The main loop processes each character in the swapped str1, attempting to match it against the current position in str2. If a match is found via the check function, both pointers advance. If pointer j reaches the end of str2 before processing all of str1, the function returns false. Otherwise, it returns true after processing all characters.

## Complexity

- **Time:** O(n * m)
- **Space:** O(1)

## Stats

- Submitted: 2026-04-21 06:44 UTC
- Runtime: 5 ms
- Memory: 17.2 MB
- Language: C++
