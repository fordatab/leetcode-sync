# The Skyline Problem

**Difficulty:** Hard
**Tags:** sweep-line, heap, priority-queue, sorting, geometry

## Problem

Given an array of buildings where each building is defined by its left x-coordinate, right x-coordinate, and height, compute the skyline as a sequence of key points representing height changes when viewing all buildings from a distance. The output must be sorted by x-coordinate, and consecutive segments at the same height must be merged. Buildings can number up to 10,000 with coordinates and heights up to 2^31 - 1.

## Approach

The solution uses an event-based sweep line approach combined with a priority queue to track active buildings. First, it creates events for both the left and right edges of each building, storing the building index with each edge position. After sorting all edges by x-coordinate, it processes them left to right. At each unique x-position, the algorithm adds newly starting buildings (left edges) to a max-heap that stores (height, right-edge) pairs. It then removes expired buildings whose right edges are at or before the current position. The current maximum height is determined from the top of the heap, and if this height differs from the previous height, a new key point is added to the result. This process continues until all edges are processed, producing the final skyline.

## Complexity

- **Time:** O(n^2 log n)
- **Space:** O(n)

## Stats

- Submitted: 2026-02-06 04:55 UTC
- Runtime: 24 ms
- Memory: 30.8 MB
- Language: C++
