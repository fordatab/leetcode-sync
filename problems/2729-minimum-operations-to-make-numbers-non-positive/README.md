# Minimum Operations to Make Numbers Non-positive

**Difficulty:** Hard
**Tags:** binary-search, greedy, math, array

## Problem

Given an array of positive integers and two values x and y (where x > y), find the minimum number of operations needed to make all array elements non-positive. Each operation selects one index i, decrements nums[i] by x, and decrements all other elements by y. The goal is to determine how many such operations are required.

## Approach

The solution uses binary search on the answer. For a given number of operations `ct`, we can check if it's sufficient by verifying that each element can be reduced to zero or below.

The key insight is that if we perform `ct` total operations, every element receives at least `ct * y` reduction (from the operations on other indices). For each element, we calculate how much remains after this baseline reduction. If positive, we need dedicated operations on that index, where each gives an additional `(x - y)` reduction beyond the baseline.

For each element, we compute `remain = nums[i] - ct * y`. If positive, we need `ceil(remain / (x - y))` operations specifically targeting this index. We sum these required targeted operations across all elements. If the total needed operations is at most `ct`, then `ct` operations suffice.

Binary search finds the minimum `ct` where this feasibility check passes, searching from 0 to INT_MAX.

## Complexity

- **Time:** O(n log(max_value))
- **Space:** O(1)

## Stats

- Submitted: 2025-12-02 03:08 UTC
- Runtime: 46 ms
- Memory: 78 MB
- Language: C++
