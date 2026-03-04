# Height Checker

**Difficulty:** Easy
**Tags:** counting-sort, array, sorting

## Problem

Given an array of student heights in their current standing order, determine how many students are not in the correct position compared to where they should be if the array were sorted in non-decreasing order. The task is to count the number of indices where the current height differs from what the sorted height would be at that position. Constraints include array lengths up to 100 and height values between 1 and 100.

## Approach

The solution uses counting sort to determine mismatches without explicitly creating a sorted array. It first builds a frequency array `count` of size 101, where `count[h]` stores how many students have height `h`. Then it performs a two-pointer traversal: pointer `i` iterates through possible height values (1 to 100), and pointer `j` tracks positions in the original array. For each position `j`, the algorithm finds the next height that should appear (the smallest height with remaining count > 0) and compares it with `heights[j]`. If they differ, it increments the mismatch counter. The count for that height is decremented, and the process continues until all positions are checked. This approach leverages the limited range of height values to achieve better performance than comparison-based sorting.

## Complexity

- **Time:** O(n + k)
- **Space:** O(k)

## Stats

- Submitted: 2026-03-04 11:09 UTC
- Runtime: 0 ms
- Memory: 11 MB
- Language: C++
