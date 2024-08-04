# Widest Vertical Area Between Two Points Containing No Points

**Difficulty:** Easy
**Tags:** sorting, array, greedy

## Problem

Given n points on a 2D plane, find the maximum width of a vertical strip (extending infinitely along the y-axis) between two consecutive x-coordinates such that no points lie strictly inside the strip. Points can have x-coordinates from 0 to 10^9, and there are between 2 and 10^5 points total.

## Approach

The solution ignores the y-coordinates entirely since vertical areas extend infinitely along the y-axis. It sorts the points array, which by default sorts by the first element (x-coordinate). After sorting, consecutive points in the array represent adjacent x-coordinates from left to right. The algorithm then iterates through the sorted points, computing the difference between each pair of consecutive x-coordinates and tracking the maximum difference found. This maximum difference is the widest vertical gap where no points exist in between.

## Complexity

- **Time:** O(n log n)
- **Space:** O(log n)

## Stats

- Submitted: 2024-08-04 08:01 UTC
- Runtime: 189 ms
- Memory: 70.1 MB
- Language: C++
