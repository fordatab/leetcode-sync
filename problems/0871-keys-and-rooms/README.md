# Keys and Rooms

**Difficulty:** Medium
**Tags:** depth-first-search, graph, recursion, visited-tracking

## Problem

Given n rooms numbered 0 to n-1 where room 0 is initially unlocked, determine if all rooms can be visited. Each room contains keys to other rooms, and you can only enter a locked room if you have its key. The input is an array where each element lists the keys found in that room. Constraints include up to 1000 rooms and a total of up to 3000 keys across all rooms.

## Approach

The solution uses depth-first search (DFS) to explore all reachable rooms starting from room 0. It maintains a boolean vector to track which rooms have been visited. Beginning at room 0 (marked as visited), the DFS recursively visits each room whose key is found, marking it as visited before exploring its keys. After the traversal completes, the code checks if all rooms in the visited array are true; if any room remains unvisited, it returns false, otherwise true. The key insight is that this is a graph reachability problem where rooms are nodes and keys represent directed edges.

## Complexity

- **Time:** O(n + k)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-08 00:36 UTC
- Runtime: 11 ms
- Memory: 13.6 MB
- Language: C++
