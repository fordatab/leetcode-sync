# Kth Missing Positive Number

**Difficulty:** Easy
**Tags:** binary-search, array, math

## Problem

Given a strictly increasing array of positive integers and an integer k, find the kth positive integer that does not appear in the array. The array contains integers between 1 and 1000 with length up to 1000, and k is at most 1000. The goal is to identify which positive integer is the kth one missing from the sequence.

## Approach

This solution uses binary search to efficiently locate the kth missing positive number. The key insight is that at any index `mid`, the number of missing positive integers up to that point can be calculated as `arr[mid] - mid - 1` (since if no numbers were missing, `arr[mid]` would equal `mid + 1`).

The algorithm performs binary search on the array indices. For each middle index, it computes how many positive integers are missing to the left of that position. If fewer than k numbers are missing (`missing_left < k`), the kth missing number must be to the right, so we move left pointer forward. Otherwise, we move right pointer backward.

After the binary search completes, `l` points to the position just past where the kth missing number would be inserted. The final answer is `l + k`, which accounts for the index offset plus the k missing numbers we're looking for.

## Complexity

- **Time:** O(log n)
- **Space:** O(1)

## Stats

- Submitted: 2026-06-14 00:41 UTC
- Runtime: 0 ms
- Memory: 13.3 MB
- Language: C++
