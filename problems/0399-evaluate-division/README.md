# Evaluate Division

**Difficulty:** Medium
**Tags:** graph, depth-first-search, hash-table, backtracking

## Problem

Given a set of division equations between string variables and their corresponding numeric values, along with a list of queries asking for the result of dividing one variable by another, determine the answer for each query. If a query involves undefined variables or variables not connected through the given equations, return -1.0. The input constraints include up to 20 equations and 20 queries, with variable names up to 5 characters long.

## Approach

The solution models the equations as a weighted directed graph where each variable is a node and each division relationship is represented by bidirectional edges. For an equation A/B = value, it creates edges from A to B with weight 'value' and from B to A with weight '1/value'. Self-loops with weight 1 are also added for each variable.

For each query, a depth-first search (DFS) traverses the graph from the source variable to the destination variable. The DFS maintains a visited set to avoid cycles and multiplies edge weights along the path. If the destination is found as a neighbor, the edge weight is returned directly. If found through a recursive path, the product of all edge weights along that path is computed.

If either variable in a query doesn't exist in the graph or no path connects them, the function returns -1.0.

## Complexity

- **Time:** O(q * (v + e))
- **Space:** O(v + e)

## Stats

- Submitted: 2024-09-02 04:33 UTC
- Runtime: 0 ms
- Memory: 11.2 MB
- Language: C++
