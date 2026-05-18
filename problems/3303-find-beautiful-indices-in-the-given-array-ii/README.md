# Find Beautiful Indices in the Given Array II

**Difficulty:** Hard
**Tags:** string-matching, kmp-algorithm, binary-search, two-pointers, pattern-matching

## Problem

Given a string s and two patterns a and b, find all indices i where pattern a occurs in s, such that there exists at least one occurrence of pattern b within distance k from i (i.e., |i - j| ≤ k for some occurrence j of b). The constraints allow strings up to 500,000 characters, requiring an efficient substring matching algorithm.

## Approach

The solution uses the **KMP (Knuth-Morris-Pratt) algorithm** to efficiently find all occurrences of both patterns in the string.

First, it implements a helper function `getLPS` that builds the Longest Prefix Suffix array, which is the preprocessing step for KMP. The `kmp` function then uses this LPS array to find all starting indices where a pattern occurs in the text in linear time.

After finding all occurrences of pattern `a` (stored in `indices_a`) and pattern `b` (stored in `indices_b`), the algorithm iterates through each occurrence of `a`. For each position `pos_a`, it uses binary search (`lower_bound`) on the sorted `indices_b` array to find the first occurrence of `b` that is at least `pos_a - k`. If this occurrence exists and is also at most `pos_a + k`, then `pos_a` qualifies as a beautiful index.

The binary search optimization is crucial: instead of checking all occurrences of `b` for each occurrence of `a`, we leverage the fact that `indices_b` is sorted to find valid matches in O(log m) time per `a` occurrence.

## Complexity

- **Time:** O(n + m + p*log(q))
- **Space:** O(n + m)

## Stats

- Submitted: 2026-05-18 20:37 UTC
- Runtime: 82 ms
- Memory: 90.2 MB
- Language: C++
