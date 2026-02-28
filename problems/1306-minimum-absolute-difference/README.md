# Minimum Absolute Difference

**Difficulty:** Easy
**Tags:** sorting, greedy, array, hash-table

## Problem

Given an array of distinct integers, identify all pairs of elements that have the smallest absolute difference among all possible pairs. Return these pairs in ascending order, where each pair [a, b] has a < b and their difference equals the minimum absolute difference found in the array. The array can contain up to 10^5 elements with values ranging from -10^6 to 10^6.

## Approach

The solution first sorts the input array in ascending order. After sorting, the minimum absolute difference can only occur between adjacent elements, so the code iterates through consecutive pairs. It uses a map where keys are absolute differences and values are lists of pairs with that difference. For each adjacent pair (arr[i], arr[i+1]), it calculates their absolute difference and stores the pair in the map under that difference key. Since the map automatically orders keys in ascending order, the first entry (accessed via `mp.begin()`) contains the minimum difference as the key, and its associated value is the list of all pairs with that minimum difference. The solution returns this list directly.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2026-02-28 11:04 UTC
- Runtime: 79 ms
- Memory: 61.5 MB
- Language: C++
