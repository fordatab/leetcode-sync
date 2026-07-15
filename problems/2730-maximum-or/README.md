# Maximum OR

**Difficulty:** Medium
**Tags:** bit-manipulation, prefix-sum, greedy, array

## Problem

Given an array of integers and a parameter k, you can multiply any element by 2 up to k times total. The goal is to maximize the bitwise OR of all elements in the array after performing at most k multiplication operations. The array can have up to 10^5 elements with values up to 10^9, and k is at most 15.

## Approach

The solution uses prefix and suffix OR arrays to efficiently evaluate the result of applying all k doublings to each individual element.

First, it precomputes `prefixOR[i]`, which stores the bitwise OR of all elements from index 0 to i-1, and `suffixOR[i]`, which stores the OR of all elements from index i+1 to the end. These arrays allow us to quickly compute the OR of all elements except the one at index i.

For each position i, the code calculates what the total OR would be if we applied all k doublings to `nums[i]` (by left-shifting it by k bits, equivalent to multiplying by 2^k), then ORing it with the prefix OR (elements before i) and suffix OR (elements after i).

The maximum value across all positions is returned. This greedy approach works because concentrating all doublings on a single element maximizes the contribution of high-order bits to the final OR result.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2026-07-15 06:57 UTC
- Runtime: 12 ms
- Memory: 101.8 MB
- Language: C++
