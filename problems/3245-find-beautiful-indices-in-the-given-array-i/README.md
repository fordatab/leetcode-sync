# Find Beautiful Indices in the Given Array I

**Difficulty:** Medium
**Tags:** string-matching, two-pointers, greedy

## Problem

Given a string s and two pattern strings a and b, find all indices i where pattern a occurs in s, such that there exists at least one occurrence of pattern b within distance k from i. The distance between two indices is the absolute difference of their positions. Return all such beautiful indices in sorted order.

## Approach

The solution uses a greedy string matching approach. It iterates through the string `s` to find all occurrences of pattern `a` using the `find()` method. For each occurrence of `a` at position `pos`, it searches for pattern `b` starting from position `max(0, pos - k)` to check if there's a match within the allowed distance. If a match of `b` is found at `pos2` and the distance `|pos2 - pos|` is at most `k`, the index `pos` is added to the result. The search continues by incrementing the starting position to `pos + 1` to find the next occurrence of `a`. However, this approach has a flaw: it only checks for the first occurrence of `b` starting from `pos - k`, which may miss valid occurrences of `b` that appear later within the valid range `[pos - k, pos + k]`. Despite this limitation, the code was accepted.

## Complexity

- **Time:** O(n * (m + p))
- **Space:** O(1)

## Stats

- Submitted: 2026-05-18 20:20 UTC
- Runtime: 110 ms
- Memory: 16.5 MB
- Language: C++
