# Cheapest Flights Within K Stops

**Difficulty:** Medium
**Tags:** graph, breadth-first-search, shortest-path, queue

## Problem

Given a directed graph of n cities with weighted edges representing flight prices, find the minimum cost to travel from a source city to a destination city using at most k intermediate stops. If no valid path exists within the stop constraint, return -1. The graph can have up to 100 nodes and at most n*(n-1)/2 edges, with edge weights between 1 and 10,000.

## Approach

This solution uses a level-by-level breadth-first search (BFS) approach with distance tracking. It builds an adjacency list from the flights array, then performs BFS starting from the source city. The algorithm processes nodes level by level, where each level represents one additional stop in the journey.

A distance array tracks the minimum cost to reach each city discovered so far. For each node dequeued, the solution examines all neighboring cities and updates their distances if a cheaper path is found through the current node. When a better price is discovered, that neighbor is added to the queue with its new cost.

The BFS continues for at most k+1 levels (allowing k intermediate stops), processing all nodes at each level before incrementing the stop counter. After completing the search within the stop limit, the algorithm returns the distance to the destination if reachable, otherwise -1.

## Complexity

- **Time:** O(k * E)
- **Space:** O(n + E)

## Stats

- Submitted: 2024-08-12 07:29 UTC
- Runtime: 18 ms
- Memory: 17.5 MB
- Language: C++
