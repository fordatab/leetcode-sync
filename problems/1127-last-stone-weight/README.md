# Last Stone Weight

**Difficulty:** Easy
**Tags:** heap, priority-queue, greedy, simulation

## Problem

Given an array of stone weights, repeatedly select the two heaviest stones and smash them together. If their weights differ, a new stone with weight equal to their difference remains; otherwise both are destroyed. Return the weight of the last remaining stone, or 0 if none remain. The array contains 1 to 30 stones, each weighing between 1 and 1000.

## Approach

The solution uses a max-heap (priority queue) to efficiently track and retrieve the heaviest stones. Initially, all stone weights are inserted into the heap. While at least two stones remain, the algorithm extracts the two heaviest stones, compares their weights, and if they differ, pushes the difference back into the heap. This process continues until at most one stone remains. Finally, if the heap is empty, 0 is returned; otherwise, the weight of the last stone is returned.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-18 08:12 UTC
- Runtime: 0 ms
- Memory: 9.6 MB
- Language: C++
