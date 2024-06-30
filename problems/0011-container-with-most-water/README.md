# Container With Most Water

**Difficulty:** Medium
**Tags:** two-pointers, greedy, array

## Problem

Given an array of non-negative integers representing the heights of vertical lines at positions 0 through n-1, find two lines that form a container with the x-axis such that the container holds the maximum amount of water. The container's capacity is determined by the shorter of the two lines multiplied by the distance between them. The array length is between 2 and 100,000, and heights range from 0 to 10,000.

## Approach

This solution uses a two-pointer technique starting from the outermost positions. It initializes two pointers at the leftmost and rightmost ends of the array, then iteratively calculates the water area formed by these two lines.

At each step, the area is computed as the minimum of the two heights (since water is limited by the shorter line) multiplied by the horizontal distance between them. This area is compared against the running maximum.

The key insight is to always move the pointer pointing to the shorter line inward. Moving the taller line's pointer can only decrease the area (since width decreases and height can't increase), but moving the shorter line's pointer might find a taller line that increases the area despite the reduced width.

The algorithm continues until the two pointers meet, having explored all potentially optimal containers by greedily eliminating configurations that cannot improve the maximum area.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-06-30 20:58 UTC
- Runtime: 68 ms
- Memory: 61.4 MB
- Language: C++
