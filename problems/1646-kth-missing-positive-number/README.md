# Kth Missing Positive Number

**Difficulty:** Easy
**Tags:** binary-search, array, math

## Problem

Given a sorted array of distinct positive integers and an integer k, find the kth positive integer that does not appear in the array. The array is strictly increasing, contains values between 1 and 1000, and has length up to 1000.

## Approach

The solution uses binary search to efficiently locate where the kth missing number falls. At any index `mid`, the number of missing positive integers to its left can be calculated as `arr[mid] - mid - 1` (since if no numbers were missing, `arr[mid]` would equal `mid + 1`). 

The algorithm maintains a search window with left (`l`) and right (`r`) pointers. At each step, it computes the count of missing numbers to the left of the midpoint. If fewer than k numbers are missing to the left of `mid`, the kth missing number must be to the right, so `l` moves to `mid + 1`. Otherwise, it's to the left or at `mid`, so `r` moves to `mid - 1`.

When the loop terminates, `l` points to the position just after where we've confirmed fewer than k missing numbers. The kth missing number is then `l + k`, which accounts for the index offset and the remaining missing count.

## Complexity

- **Time:** O(log n)
- **Space:** O(1)

## Stats

- Submitted: 2026-06-14 00:41 UTC
- Runtime: 0 ms
- Memory: 13.3 MB
- Language: C++
