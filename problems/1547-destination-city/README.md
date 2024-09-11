# Destination City

**Difficulty:** Easy
**Tags:** hash-table, string, graph

## Problem

Given an array of directed path pairs where each pair represents a one-way connection between two cities, find the unique city that has no outgoing paths. The input forms a linear chain without cycles, guaranteeing exactly one such destination city exists. The array contains between 1 and 100 paths, with city names being strings of 1-10 characters.

## Approach

The solution uses a hash set to track all cities that have outgoing paths. First, it iterates through all path pairs and inserts each source city (the first element) into the set. Then, it performs a second pass through the paths, checking each destination city (the second element) to see if it appears in the set. The first destination city not found in the set is the answer, as it has no outgoing path. This works because the destination city is the only one that appears as a destination but never as a source.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-11 02:25 UTC
- Runtime: 14 ms
- Memory: 14.2 MB
- Language: C++
