# Two Sum II - Input Array Is Sorted

**Difficulty:** Medium
**Tags:** two-pointers, array, binary-search

## Problem

Given a sorted array of integers (1-indexed) and a target value, find two distinct elements that sum to the target and return their 1-indexed positions. The array contains between 2 and 30,000 elements with values ranging from -1000 to 1000, and exactly one valid pair is guaranteed to exist. The solution must use constant extra space.

## Approach

The solution uses a two-pointer technique that takes advantage of the sorted array property. It initializes one pointer (`r`) at the beginning of the array and another pointer (`l`) at the end. In each iteration, it computes the sum of the elements at these two positions. If the sum equals the target, it returns the 1-indexed positions by adding 1 to each pointer. If the sum exceeds the target, the right pointer moves left (decreasing the sum), and if the sum is too small, the left pointer moves right (increasing the sum). This process continues until the target sum is found, which is guaranteed by the problem constraints.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-06-30 07:01 UTC
- Runtime: 15 ms
- Memory: 17.9 MB
- Language: C++
