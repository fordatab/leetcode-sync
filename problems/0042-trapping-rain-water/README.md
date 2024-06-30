# Trapping Rain Water

**Difficulty:** Hard
**Tags:** two-pointers, array, greedy

## Problem

Given an array of non-negative integers representing elevation heights where each element has width 1, calculate the total volume of water that can be trapped between the bars after rainfall. The array can contain up to 20,000 elements with heights up to 100,000.

## Approach

This solution uses a two-pointer approach with left and right pointers starting at opposite ends of the array. It maintains the maximum height seen so far from both the left side (`l_max`) and right side (`r_max`). At each step, it moves the pointer from the side with the smaller maximum height, updating that side's maximum and accumulating trapped water.

The key insight is that water trapped at any position is determined by the minimum of the maximum heights to its left and right. By tracking both maximums and always advancing from the side with the smaller maximum, we ensure that the limiting factor (the smaller of the two maximums) is known for the current position.

When advancing the left pointer, water trapped equals `l_max - height[l]` because `l_max` represents the water level (guaranteed to be at least as high as any bar to the right due to `r_max` being larger). Similarly, when advancing the right pointer, trapped water is `r_max - height[r]`. The process continues until the pointers meet, accumulating the total trapped water.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-06-30 23:51 UTC
- Runtime: 13 ms
- Memory: 22.3 MB
- Language: C++
