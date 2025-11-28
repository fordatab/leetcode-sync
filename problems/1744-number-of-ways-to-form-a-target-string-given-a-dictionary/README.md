# Number of Ways to Form a Target String Given a Dictionary

**Difficulty:** Hard
**Tags:** dynamic-programming, string, counting, preprocessing

## Problem

Given a list of equal-length strings and a target string, count how many ways you can form the target by selecting characters from successive column positions across the dictionary words. You must build the target left-to-right, and once you use column k, you cannot use any column at or before k again. The constraints allow up to 1000 words of length up to 1000, and a target of length up to 1000. Return the count modulo 10^9 + 7.

## Approach

The solution uses dynamic programming with a preprocessing step. First, it builds a frequency table `freq[col][char]` that counts how many times each letter appears at each column position across all dictionary words.

The DP state `dp[i][j]` represents the number of ways to form the first `j` characters of the target using the first `i` columns of the dictionary. The base case is `dp[0][0] = 1` (one way to form zero characters using zero columns).

For each column `i` from 0 to m-1, the solution considers two transitions: (1) skip column `i` entirely, carrying forward `dp[i][j]` to `dp[i+1][j]` for all `j`, and (2) use column `i` to match `target[j]`, multiplying `dp[i][j]` by the frequency of `target[j]` at column `i` and adding to `dp[i+1][j+1]`. All additions are taken modulo 10^9 + 7.

The final answer is `dp[m][n]`, representing the number of ways to form all `n` characters of the target using up to `m` columns.

## Complexity

- **Time:** O(w * m + m * n)
- **Space:** O(m * n)

## Stats

- Submitted: 2025-11-28 11:25 UTC
- Runtime: 75 ms
- Memory: 83.5 MB
- Language: C++
