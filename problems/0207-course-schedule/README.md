# Course Schedule

**Difficulty:** Medium
**Tags:** graph, depth-first-search, cycle-detection, topological-sort, memoization

## Problem

Given a number of courses and a list of prerequisite pairs, determine whether it's possible to complete all courses. Each prerequisite pair [a, b] means course b must be taken before course a. The task is to detect if the dependency graph contains a cycle, which would make it impossible to complete all courses. Constraints include up to 2000 courses and 5000 prerequisite relationships.

## Approach

The solution builds an adjacency list representation of the course dependency graph, where each course maps to its list of prerequisites. It then performs depth-first search (DFS) from each course to detect cycles.

During DFS, a `visiting` array tracks courses currently in the recursion stack. If we encounter a course already being visited, a cycle exists and we return false. The algorithm also employs memoization: once a course's prerequisites are fully validated (no cycles found), its prerequisite list is cleared, so future visits can skip re-checking it.

For each course, the DFS recursively validates all its prerequisites. If any prerequisite path contains a cycle, the function returns false. If a course has no prerequisites (empty list), it's trivially completable. After exploring all prerequisites of a course without finding cycles, the course is marked as safe by clearing its prerequisite list and removing it from the visiting set.

## Complexity

- **Time:** O(V + E)
- **Space:** O(V + E)

## Stats

- Submitted: 2024-08-09 01:08 UTC
- Runtime: 10 ms
- Memory: 17.4 MB
- Language: C++
