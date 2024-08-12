# Reconstruct Itinerary

**Difficulty:** Hard
**Tags:** graph, depth-first-search, eulerian-path, greedy, backtracking

## Problem

Given a collection of airline tickets represented as pairs of departure and arrival airports, construct a complete itinerary starting from "JFK" that uses every ticket exactly once. When multiple valid itineraries exist, return the one with the smallest lexicographical ordering. The input guarantees at least one valid solution exists, with up to 300 tickets where each airport code is exactly 3 uppercase letters.

## Approach

The solution uses Hierholzer's algorithm to find an Eulerian path in a directed graph where airports are nodes and tickets are edges.

First, it builds an adjacency list using an unordered_map where each airport maps to a multiset of its destinations. The multiset automatically maintains destinations in lexicographical order and allows duplicate edges.

Starting from "JFK", it performs a depth-first traversal. At each airport, it greedily visits the lexicographically smallest unvisited destination by taking the first element from the multiset and removing it (simulating ticket usage). This continues recursively until no more destinations are available from the current airport.

The key insight is that airports are added to the route in post-order (after all their destinations are exhausted), which produces the path in reverse. By reversing the final route, we obtain the correct itinerary from "JFK" to the final destination.

## Complexity

- **Time:** O(E log E)
- **Space:** O(E)

## Stats

- Submitted: 2024-08-12 04:25 UTC
- Runtime: 18 ms
- Memory: 18.1 MB
- Language: C++
