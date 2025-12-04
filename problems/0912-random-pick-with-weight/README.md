# Random Pick with Weight

**Difficulty:** Medium
**Tags:** prefix-sum, binary-search, random, cumulative-sum

## Problem

Given an array of positive integers representing weights, implement a data structure that can randomly select an index where the probability of selecting index i is proportional to its weight w[i]. The selection probability for each index should be w[i] divided by the sum of all weights. The array can have up to 10,000 elements with weights up to 100,000 each, and the pickIndex function will be called up to 10,000 times.

## Approach

The solution uses a prefix sum array combined with binary search to achieve weighted random selection.

**Construction Phase:** During initialization, build a prefix sum array where each element stores the cumulative sum of weights up to that index. Store the total sum (last element of prefix array) separately.

**Selection Phase:** Generate a random number in the range [1, total_sum] (inclusive). Use `lower_bound` to perform binary search on the prefix sum array to find the first position where the prefix sum is greater than or equal to the random number. This maps random numbers to indices proportionally to their weights.

**Key Insight:** By dividing the range [1, total_sum] into segments of size w[i] for each index i, and then finding which segment a random number falls into via binary search, we naturally achieve the correct probability distribution. The use of `rand() % m + 1` ensures we generate numbers from 1 to m inclusive, and `lower_bound` finds the corresponding index.

## Complexity

- **Time:** O(n) for construction, O(log n) per pickIndex call
- **Space:** O(n)

## Stats

- Submitted: 2025-12-04 03:03 UTC
- Runtime: 12 ms
- Memory: 47.2 MB
- Language: C++
