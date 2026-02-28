# Find Occurrences of an Element in an Array

**Difficulty:** Medium
**Tags:** array, preprocessing, indexing

## Problem

Given an array of integers, a target value x, and a list of queries, determine the array index of the k-th occurrence of x for each query k. If x appears fewer than k times in the array, return -1 for that query. Both the input array and queries can contain up to 100,000 elements, and array values range from 1 to 10,000.

## Approach

The solution uses a preprocessing step followed by lookup. First, it iterates through the input array once to collect the indices of all positions where the target value x appears, storing them in sequential order in a vector called `occurrs`. Then, for each query value q, it checks whether q is within the valid range (1 to the number of occurrences found). If the query asks for more occurrences than exist, it returns -1; otherwise, it performs a direct array lookup at index q-1 (adjusting for 1-based querying) to retrieve the corresponding original array index. This approach trades memory for query speed by building an index structure upfront.

## Complexity

- **Time:** O(n + m)
- **Space:** O(k)

## Stats

- Submitted: 2026-02-28 11:23 UTC
- Runtime: 16 ms
- Memory: 185.7 MB
- Language: C++
