# Minimum Number of Arrows to Burst Balloons

**Difficulty:** Medium
**Tags:** greedy, interval-scheduling, sorting, array

## Problem

Given intervals representing horizontal spans of balloons on a wall, find the minimum number of vertical arrows needed to burst all balloons. An arrow at position x bursts any balloon whose interval contains x. The input is an array of intervals with up to 10^5 elements, and coordinates can range from -2^31 to 2^31-1.

## Approach

The solution uses a greedy interval scheduling approach. First, it sorts all balloon intervals by their start positions. Then it iterates through the sorted intervals, maintaining the rightmost position where an arrow can be placed to hit the current group of overlapping balloons.

For each new balloon interval, the algorithm checks if it overlaps with the current arrow position (tracked as the minimum end point seen so far in the current group). If the next balloon's start is less than or equal to the current arrow position, they can be burst by the same arrow, so the arrow position is updated to the minimum of the current position and the new balloon's end point. When a balloon doesn't overlap, a new arrow is needed.

The key insight is that by always choosing the earliest possible end point among overlapping balloons, we maximize the chance of hitting subsequent balloons with the same arrow. The algorithm counts one arrow for each disjoint group of overlapping intervals found during the traversal.

## Complexity

- **Time:** O(n log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-18 05:04 UTC
- Runtime: 244 ms
- Memory: 93.7 MB
- Language: C++
