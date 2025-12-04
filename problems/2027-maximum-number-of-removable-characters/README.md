# Maximum Number of Removable Characters

**Difficulty:** Medium
**Tags:** binary-search, two-pointers, string, greedy

## Problem

Given a string s, a subsequence p of s, and an array of indices removable, find the maximum number k such that after marking the first k indices from removable as removed in s, p remains a subsequence of the modified s. The removable array contains distinct indices, and removals are applied in order from the array.

## Approach

The solution uses binary search on the answer space combined with subsequence validation. For each candidate value k (number of removals), it checks whether p remains a subsequence of s after removing the first k indices from the removable array.

The binary search operates on the range [0, removable.length], where the search space represents possible values of k. For each mid-point, it calls a helper function that marks the first k indices as removed and then validates if p is still a subsequence.

The validation function creates a boolean array to track which indices are marked for removal in O(1) lookup time. It then uses a two-pointer technique: one pointer traverses s while skipping removed indices, and the other traverses p. Characters are matched when not removed, and if all of p is matched, the validation succeeds.

The binary search adjusts based on validation results: if k removals still preserve the subsequence, it tries larger k values (search right); otherwise, it searches for smaller k values (search left). The maximum valid k found during the search is returned.

## Complexity

- **Time:** O(n log m)
- **Space:** O(n)

## Stats

- Submitted: 2025-12-04 09:37 UTC
- Runtime: 74 ms
- Memory: 99.2 MB
- Language: C++
