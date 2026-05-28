# Find Beautiful Indices in the Given Array II

**Difficulty:** Hard
<<<<<<< HEAD
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
=======
**Tags:** string-matching, kmp-algorithm, binary-search, pattern-matching, two-pointers

## Problem

Given a string s and two pattern strings a and b, along with an integer k, find all indices i where substring a starts in s such that there exists at least one index j where substring b starts in s and the distance |j - i| is at most k. The input can be up to 500,000 characters, and both patterns can also be up to 500,000 characters long. Return all such "beautiful" indices in ascending order.

## Approach

The solution uses the KMP (Knuth-Morris-Pratt) string matching algorithm to efficiently find all occurrences of both patterns in the main string.

First, it implements a helper function to build the LPS (Longest Prefix Suffix) array, which is the preprocessing step for KMP. The LPS array tracks the length of the longest proper prefix that is also a suffix for each position in the pattern.

The kmp function then uses this LPS array to find all starting indices where a pattern occurs in the string, achieving linear time complexity instead of the naive quadratic approach.

After finding all positions where pattern a occurs (indices_a) and where pattern b occurs (indices_b), the solution iterates through each position in indices_a. For each such position pos_a, it uses binary search (lower_bound) to find the first occurrence of b at position >= pos_a - k. If this occurrence exists and is also <= pos_a + k, then pos_a satisfies the beautiful index condition and is added to the result.

## Complexity

- **Time:** O(n + m_a + m_b + |indices_a| * log(|indices_b|))
- **Space:** O(n + m_a + m_b)
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d

## Stats

- Submitted: 2026-05-18 20:37 UTC
- Runtime: 82 ms
- Memory: 90.2 MB
- Language: C++
