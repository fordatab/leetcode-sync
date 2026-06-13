# Open the Lock

**Difficulty:** Medium
**Tags:** breadth-first-search, hash-table, graph, string

## Problem

Given a 4-digit combination lock starting at "0000" where each digit can be rotated up or down (wrapping from 9 to 0 and vice versa), find the minimum number of single-digit rotations needed to reach a target combination while avoiding forbidden "deadend" combinations that permanently lock the mechanism. Each wheel can be turned independently, and up to 500 deadend combinations may exist.

## Approach

This solution uses breadth-first search (BFS) to explore all reachable lock states level by level. It maintains a queue starting with "0000" and an unordered set to track both deadends and visited states (preventing revisits). For each state dequeued, the code generates all 8 neighbors by rotating each of the 4 wheels either up or down (handling wraparound for '0' and '9'). When a neighbor hasn't been visited and isn't a deadend, it's added to the queue and marked as visited. The search proceeds in levels, incrementing a counter after processing each complete level. If the target is found during exploration, the current level count is returned; if the queue empties without finding the target, -1 is returned indicating impossibility.

## Complexity

- **Time:** O(10^4)
- **Space:** O(10^4)

## Stats

- Submitted: 2026-06-13 10:12 UTC
- Runtime: 110 ms
- Memory: 38.5 MB
- Language: C++
