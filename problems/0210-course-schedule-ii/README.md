# Course Schedule II

**Difficulty:** Medium
**Tags:** graph, depth-first-search, topological-sort, cycle-detection

## Problem

Given a number of courses and prerequisite pairs where each pair indicates one course must be completed before another, find any valid ordering to complete all courses. If courses have circular dependencies making completion impossible, return an empty array. The input size can be up to 2000 courses with potentially up to numCourses*(numCourses-1) prerequisite relationships.

## Approach

The solution uses depth-first search (DFS) with cycle detection on a directed graph where edges represent prerequisite relationships. It builds an adjacency list where each course points to its prerequisites (note: the graph is stored in reverse, with edges from dependent courses to their prerequisites). A three-state tracking system distinguishes unvisited nodes (0), currently-being-visited nodes (1), and fully-processed nodes (2). The DFS explores each course's prerequisite chain recursively; if it encounters a node marked as "visiting", a cycle exists. Successfully processed courses are appended to the output list in post-order (after all prerequisites are visited), which produces a valid topological ordering when no cycles exist. If any DFS call detects a cycle, an empty array is returned.

## Complexity

- **Time:** O(V + E)
- **Space:** O(V + E)

## Stats

- Submitted: 2024-08-09 03:08 UTC
- Runtime: 12 ms
- Memory: 17.5 MB
- Language: C++
