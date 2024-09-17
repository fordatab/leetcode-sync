# Range Sum Query - Immutable

**Difficulty:** Easy
**Tags:** array, prefix-sum, design

## Problem

Design a class that stores an integer array and efficiently answers queries about the sum of elements within a given index range (inclusive on both ends). The array contains up to 10,000 elements with values between -100,000 and 100,000, and up to 10,000 range sum queries will be made.

## Approach

The solution stores the input array directly in a private member variable. For each range sum query, it uses the `accumulate` function from the C++ standard library to compute the sum of elements from index `left` to `right` (inclusive) by iterating through the specified range. The constructor simply copies the input vector, and `sumRange` calculates the sum on-demand by adding `right + 1` to the begin iterator to ensure the right endpoint is included in the range.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-17 07:44 UTC
- Runtime: 98 ms
- Memory: 22.1 MB
- Language: C++
