# One Edit Distance

**Difficulty:** Medium
**Tags:** two-pointers, string, simulation

## Problem

Determine whether two strings differ by exactly one edit operation: inserting one character, deleting one character, or replacing one character. The strings must be exactly one edit apart — identical strings or strings requiring multiple edits should return false. String lengths can be up to 10^4 characters.

## Approach

The solution branches based on the length difference between the two strings:

**Same length (replacement check):** Walk through both strings simultaneously, counting character mismatches. If more than one mismatch is found, return false. At the end, return true only if exactly one mismatch occurred (the `changed` flag being true).

**Different length (insertion/deletion check):** First ensure the length difference is at most 1, otherwise return false immediately. Swap the strings if necessary so that `s` is always the shorter string. Use two pointers to traverse both strings. When a mismatch is found, decrement pointer `a` (to keep it aligned with the shorter string) and set the `changed` flag. If a second mismatch occurs, return false. The function returns true if the traversal completes, indicating exactly one character was inserted or deleted.

The key insight is handling the three edit cases separately based on length difference, using a single-pass scan with pointer manipulation for the insertion/deletion case.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2025-10-02 01:57 UTC
- Runtime: 0 ms
- Memory: 8.8 MB
- Language: C++
