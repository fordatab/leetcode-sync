# Remove Duplicates from Sorted Array II

**Difficulty:** Medium
**Tags:** two-pointers, array, in-place

## Problem

Given a sorted integer array, modify it in-place to ensure each distinct value appears at most twice, maintaining relative order. Return the length of the modified prefix, where elements beyond this length are irrelevant. The array has up to 30,000 elements with values ranging from -10,000 to 10,000.

## Approach

The solution uses a two-pointer technique to build the result array in-place. The first two elements are automatically valid (they can't violate the "at most twice" rule), so the write pointer `l` starts at index 2. A read pointer `r` scans from index 2 onwards. For each element at `r`, the code checks if it differs from the element two positions behind the write pointer (`nums[l-2]`). This comparison works because if `nums[r]` equals `nums[l-2]`, and the array is sorted, then placing `nums[r]` at position `l` would create three consecutive identical values. Only when `nums[r]` differs from `nums[l-2]` is it safe to copy `nums[r]` to position `l` and advance the write pointer. This ensures each value appears at most twice in the final result.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-01 08:03 UTC
- Runtime: 8 ms
- Memory: 13.7 MB
- Language: C++
