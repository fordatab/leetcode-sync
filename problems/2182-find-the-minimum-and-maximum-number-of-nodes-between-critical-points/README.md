# Find the Minimum and Maximum Number of Nodes Between Critical Points

**Difficulty:** Medium
**Tags:** linked-list, two-pointers, traversal

## Problem

Given a singly linked list, identify all critical points—nodes that are either local maxima (strictly greater than both neighbors) or local minima (strictly smaller than both neighbors). Return the minimum and maximum distances between any two distinct critical points. If fewer than two critical points exist, return [-1, -1]. The list contains between 2 and 100,000 nodes with values from 1 to 100,000.

## Approach

The solution performs a single traversal of the linked list while tracking the positions of critical points. It maintains three key variables: `first_p` (position of the first critical point), `prev_p` (position of the most recently found critical point), and the current node's position `i`. 

For each node with both a previous and next neighbor, the code checks if it's a critical point by testing whether it's either a local maximum (previous < current > next) or a local minimum (previous > current < next). 

When a critical point is found, if it's the first one, both `first_p` and `prev_p` are set to the current position. For subsequent critical points, the maximum distance is updated as the difference between the current position and the first critical point, while the minimum distance is updated as the difference between the current position and the previous critical point. After traversal, if no valid minimum distance was found (still INT_MAX), it's set to -1.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-30 00:23 UTC
- Runtime: 296 ms
- Memory: 116 MB
- Language: C++
