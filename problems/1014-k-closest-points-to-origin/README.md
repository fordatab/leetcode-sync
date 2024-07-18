# K Closest Points to Origin

**Difficulty:** Medium
**Tags:** heap, priority-queue, sorting, geometry

## Problem

Given an array of 2D points and an integer k, find the k points that have the smallest Euclidean distance from the origin (0, 0). The input contains up to 10,000 points with coordinates ranging from -10,000 to 10,000. The result can be returned in any order since uniqueness is guaranteed.

## Approach

The solution uses a max-heap (priority queue) to maintain the k closest points seen so far. For each point in the input array, it calculates the Euclidean distance from the origin using the standard distance formula with square root. Each point is stored in the heap as a pair containing its distance and its index in the original array.

The custom comparator `CompareDistance` ensures the heap behaves as a max-heap by comparing distances with the less-than operator. As points are processed, each new point-distance pair is pushed onto the heap. If the heap size exceeds k, the point with the maximum distance (at the top) is removed.

After processing all points, the heap contains exactly k points with the smallest distances. These are extracted from the heap and their corresponding coordinate vectors are collected from the original points array using the stored indices. The final result is returned as a vector of coordinate pairs.

## Complexity

- **Time:** O(n log k)
- **Space:** O(k)

## Stats

- Submitted: 2024-07-18 08:23 UTC
- Runtime: 159 ms
- Memory: 74 MB
- Language: C++
