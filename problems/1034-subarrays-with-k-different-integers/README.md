# Subarrays with K Different Integers

**Difficulty:** Hard
**Tags:** sliding-window, hash-table, two-pointers, array

## Problem

Given an array of integers and a target value k, count how many contiguous subarrays contain exactly k distinct integers. The array can have up to 20,000 elements, and both element values and k are bounded by the array length.

## Approach

The solution uses a sliding window technique with a clever transformation: instead of directly counting subarrays with exactly k distinct elements, it computes the difference between subarrays with at most k distinct elements and subarrays with at most k-1 distinct elements.

The helper function implements a two-pointer sliding window that counts all subarrays with at most k distinct integers. It maintains a hash map tracking the frequency of each element in the current window. As the right pointer expands, elements are added to the map. When the number of distinct elements exceeds k, the left pointer contracts until the constraint is satisfied again, removing elements and erasing map entries when their count drops to zero.

For each position of the right pointer, the number of valid subarrays ending at that position equals (r - l + 1), which represents all subarrays starting from any position between l and r. By subtracting helper(k-1) from helper(k), the solution isolates exactly those subarrays containing precisely k distinct integers, since subarrays with exactly k distinct elements are present in "at most k" but not in "at most k-1".

## Complexity

- **Time:** O(n)
- **Space:** O(k)

## Stats

- Submitted: 2025-09-02 02:59 UTC
- Runtime: 83 ms
- Memory: 56.2 MB
- Language: C++
