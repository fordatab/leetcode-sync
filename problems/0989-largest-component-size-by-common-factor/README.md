# Largest Component Size by Common Factor

**Difficulty:** Hard
**Tags:** union-find, prime-factorization, graph, number-theory, hash-table

## Problem

Given an array of unique positive integers, construct a graph where each number is a node and two nodes share an edge if their corresponding numbers have a common factor greater than 1. The task is to find the size of the largest connected component in this graph. The array can have up to 20,000 elements, with values ranging from 1 to 100,000.

## Approach

The solution uses a union-find (disjoint set union) data structure to group numbers that share common prime factors.

For each number in the input array, it performs trial division factorization to extract all prime factors. As each prime factor is discovered, the solution maintains a map from each factor to the indices of numbers that contain it. When a factor has been seen before (exists in the map), the current number's index is united with any previously seen index that shares this factor.

The union-find structure tracks connected components with path compression in the `find` operation and union-by-size in the `unite` operation. After processing all numbers and their factors, the solution iterates through all indices to find the maximum component size by checking the size of each root's component.

The key insight is that instead of comparing all pairs of numbers directly (which would be O(n²)), we can use prime factors as intermediaries: if two numbers share any prime factor, they belong to the same component.

## Complexity

- **Time:** O(n * sqrt(m))
- **Space:** O(n + f)

## Stats

- Submitted: 2026-01-23 21:03 UTC
- Runtime: 366 ms
- Memory: 126.6 MB
- Language: C++
