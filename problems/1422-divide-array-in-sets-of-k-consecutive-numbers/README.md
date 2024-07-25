# Divide Array in Sets of K Consecutive Numbers

**Difficulty:** Medium
**Tags:** greedy, hash-table, ordered-map, frequency-counting

## Problem

Given an array of integers and a positive integer k, determine whether the array can be partitioned into groups where each group contains exactly k consecutive integers. The array length must be divisible by k, and each element can be used in exactly one group. Return true if such a partitioning exists, false otherwise.

## Approach

The solution uses a greedy approach with a frequency map. First, it counts the occurrence of each number using a `std::map`, which maintains elements in sorted order by key. Then, it repeatedly attempts to form groups starting from the smallest remaining number. For each iteration, it takes the minimum element in the map and tries to form a consecutive sequence of k numbers starting from that element. For each number in the sequence, it decrements its count in the map and removes it if the count reaches zero. If any required number in the sequence is missing from the map, the partitioning is impossible and the function returns false. The process continues until all elements are consumed, at which point it returns true.

## Complexity

- **Time:** O(n * k)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-25 01:00 UTC
- Runtime: 132 ms
- Memory: 55 MB
- Language: C++
