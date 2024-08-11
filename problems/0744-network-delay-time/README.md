# Network Delay Time

**Difficulty:** Medium
**Tags:** graph, dijkstra, shortest-path, heap, priority-queue

## Problem

Given a directed weighted graph with n nodes (labeled 1 to n) and a list of edges with travel times, find the minimum time for a signal sent from node k to reach all nodes. If any node is unreachable from k, return -1. The graph can have up to 100 nodes and 6000 edges, with edge weights between 0 and 100.

## Approach

This solution uses Dijkstra's shortest path algorithm with a min-heap priority queue. First, it builds an adjacency list representation of the directed graph from the input edges. Then it initializes a distance array with all values set to infinity (INT_MAX) except the starting node k which is set to 0. The algorithm maintains a visited array and processes nodes in order of their current shortest distance using a priority queue. For each unvisited node dequeued, it marks it as visited and relaxes all outgoing edges, updating distances and pushing new candidates into the queue. After processing all reachable nodes, it scans the distance array: if any node remains at infinity, that node is unreachable and -1 is returned; otherwise, the maximum distance among all nodes represents the time when the last node receives the signal.

## Complexity

- **Time:** O((V + E) log V)
- **Space:** O(V + E)

## Stats

- Submitted: 2024-08-11 05:19 UTC
- Runtime: 95 ms
- Memory: 47.6 MB
- Language: C++
