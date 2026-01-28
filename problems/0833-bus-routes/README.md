# Bus Routes

**Difficulty:** Hard
**Tags:** breadth-first-search, hash-table, graph, queue

## Problem

Given an array where each element represents a circular bus route (a list of stops that bus visits repeatedly), find the minimum number of buses needed to travel from a source stop to a target stop. Each bus can be boarded at any of its stops, and you can only travel between stops by taking buses. The routes array can have up to 500 buses with a total of up to 10^5 stops across all routes, and stop numbers can be as large as 10^6.

## Approach

The solution uses BFS on the graph of bus routes rather than stops. First, it builds a mapping from each stop to all routes that visit that stop. Then it initializes the queue with all routes containing the source stop and performs level-order traversal where each level represents taking one more bus.

For each route dequeued, it first checks if the target stop is on that route—if so, it returns the current level (number of buses taken). Otherwise, it explores all stops on the current route, and for each unvisited stop, it adds all routes passing through that stop to the queue (if not already visited).

The key insight is treating routes as nodes in the graph instead of stops, which reduces the search space significantly. Two routes are "connected" if they share at least one common stop. The `visitedRoutes` set prevents revisiting the same bus route, while `visitedStops` prevents redundantly exploring stops we've already processed.

## Complexity

- **Time:** O(N * S) where N is the number of routes and S is the total number of stops across all routes
- **Space:** O(N * S) for the stop-to-routes mapping and visited sets

## Stats

- Submitted: 2026-01-28 03:28 UTC
- Runtime: 140 ms
- Memory: 71.6 MB
- Language: C++
