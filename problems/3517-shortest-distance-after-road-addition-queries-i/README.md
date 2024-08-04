# Shortest Distance After Road Addition Queries I

**Difficulty:** Medium
**Tags:** graph, breadth-first-search, shortest-path, dynamic-graph

## Problem

Given n cities numbered 0 to n-1 with initial roads connecting each city i to city i+1, process a series of queries where each query adds a new unidirectional road between two cities. After adding each road, determine the shortest path length from city 0 to city n-1. The constraints allow up to 500 cities and 500 queries, with each new road skipping at least one intermediate city.

## Approach

The solution builds an explicit graph using custom Node objects, where each node stores its value and a list of neighbor pointers. Initially, a linked chain of nodes is created representing roads from city i to i+1. For each query, the code adds a new edge by appending the destination node to the source node's neighbor list.

After processing each query, a breadth-first search (BFS) is performed starting from city 0 to find the shortest path to city n-1. The BFS uses a queue to explore nodes level by level, maintaining a visited array to track the distance to each city and avoid revisiting nodes.

The distance tracking works by storing each node's distance from the source when first visited. When the destination city n-1 is reached, its recorded distance represents the shortest path length. This BFS runs after every single query addition, returning the updated shortest distance each time.

## Complexity

- **Time:** O(q * (n + e))
- **Space:** O(n + e)

## Stats

- Submitted: 2024-08-04 03:11 UTC
- Runtime: 203 ms
- Memory: 164.4 MB
- Language: C++
