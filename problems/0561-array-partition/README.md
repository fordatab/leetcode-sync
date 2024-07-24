# Array Partition

**Difficulty:** Easy
**Tags:** greedy, sorting, array

## Problem

Given an array of 2n integers, partition the elements into n pairs such that the sum of the minimum element from each pair is maximized. The array length is always even (between 2 and 20,000 elements), and values range from -10,000 to 10,000.

## Approach

The solution sorts the array in descending order, then iterates through pairs of consecutive elements, selecting the minimum from each pair and accumulating the sum. The key insight is that after sorting in descending order, pairing consecutive elements ensures that we maximize the sum of minimums — by pairing the largest element with the second-largest, the third-largest with the fourth-largest, and so on, we minimize what is "wasted" by the min() operation. In each pair of consecutive elements from the sorted array, the second element (at index 2*x+1) is always the smaller one, so it gets added to the result.

## Complexity

- **Time:** O(n log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-24 00:16 UTC
- Runtime: 44 ms
- Memory: 34.2 MB
- Language: C++
