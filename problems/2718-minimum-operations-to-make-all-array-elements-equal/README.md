# Minimum Operations to Make All Array Elements Equal

**Difficulty:** Medium
**Tags:** binary-search, prefix-sum, sorting, array

## Problem

Given an array of positive integers and a list of query values, determine the minimum number of increment/decrement operations needed to transform all array elements to each query value. Each operation changes one element by 1, and the array resets between queries. Arrays can contain up to 10^5 elements, and values can reach 10^9.

## Approach

The solution sorts the input array and builds a prefix sum array to enable efficient range sum queries. For each query value, it uses binary search (lower_bound) to find the partition point where elements transition from being less than the query to greater-or-equal. 

The key insight is that the total cost splits into two parts: elements smaller than the query need to be increased (each by `query - nums[i]`), and elements larger need to be decreased (each by `nums[i] - query`). Using the prefix sums, the cost for the left partition is `count_left * query - sum_left`, and for the right partition is `sum_right - count_right * query`.

The binary search locates the boundary, and the prefix sum array allows O(1) calculation of both the count and sum for each partition. The total operations for a query is the sum of operations needed for both partitions.

## Complexity

- **Time:** O(n log n + m log n)
- **Space:** O(n)

## Stats

- Submitted: 2026-02-28 10:48 UTC
- Runtime: 374 ms
- Memory: 86.4 MB
- Language: C++
