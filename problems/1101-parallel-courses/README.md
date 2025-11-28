# Parallel Courses

**Difficulty:** Medium
**Tags:** topological-sort, graph, breadth-first-search, directed-graph, queue

## Problem

Given n courses numbered 1 to n and a list of prerequisite relationships where each relationship specifies that one course must be completed before another, determine the minimum number of semesters required to complete all courses. In each semester, you can take any number of courses simultaneously as long as all their prerequisites were completed in previous semesters. If a cycle exists in the prerequisites (making it impossible to complete all courses), return -1. Constraints include up to 5000 courses and 5000 prerequisite relationships.

## Approach

The solution uses topological sorting with Kahn's algorithm via breadth-first search (BFS) to process courses level by level, where each level represents one semester.

First, it builds an adjacency list representation of the prerequisite graph and computes the in-degree (number of prerequisites) for each course. Courses with zero in-degree have no prerequisites and can be taken in the first semester, so they're added to a queue.

The BFS processes courses in layers: in each iteration, all courses currently in the queue (representing one semester) are dequeued. For each course taken, the algorithm decrements the in-degree of all dependent courses. When a course's in-degree reaches zero (all prerequisites satisfied), it's added to the queue for the next semester.

The number of BFS layers (iterations) equals the number of semesters needed. After processing, if any course remains unvisited (checked via a boolean array), it means a cycle exists in the prerequisite graph, so the function returns -1. Otherwise, it returns the iteration count.

## Complexity

- **Time:** O(n + m)
- **Space:** O(n + m)

## Stats

- Submitted: 2025-11-28 09:21 UTC
- Runtime: 196 ms
- Memory: 33.8 MB
- Language: C++
