# Parallel Courses III

**Difficulty:** Hard
**Tags:** depth-first-search, memoization, directed-acyclic-graph, topological-sort, dynamic-programming

## Problem

Given n courses numbered 1 to n, a list of prerequisite pairs indicating which courses must be completed before others, and an array specifying how many months each course takes, determine the minimum total months needed to complete all courses. Multiple courses can be taken simultaneously as long as their prerequisites are satisfied. The dependency graph is guaranteed to be acyclic.

## Approach

The solution uses **depth-first search with memoization** to compute the earliest completion time for each course. It builds an adjacency list representing the prerequisite graph where an edge from course A to course B means A must be completed before B. For each course, the DFS recursively finds the maximum completion time among all its prerequisite courses, then adds that course's own duration. The base case is when a course has no prerequisites (the recursion bottoms out). Memoization prevents recomputing the same course's completion time. Finally, the algorithm runs DFS from every course and returns the maximum completion time across all courses, which represents the total time needed when courses with no dependencies can start immediately and proceed in parallel.

## Complexity

- **Time:** O(n + e)
- **Space:** O(n + e)

## Stats

- Submitted: 2025-10-02 08:49 UTC
- Runtime: 112 ms
- Memory: 153.7 MB
- Language: C++
