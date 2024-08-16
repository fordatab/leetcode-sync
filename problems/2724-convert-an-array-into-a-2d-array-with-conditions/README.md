# Convert an Array Into a 2D Array With Conditions

**Difficulty:** Medium
**Tags:** hash-table, greedy, counting, array

## Problem

Given an integer array, construct a 2D array where all original elements are distributed across rows such that each row contains only distinct integers. The goal is to minimize the number of rows needed. Elements can be arranged in any order, and rows may have different lengths.

## Approach

The solution uses a frequency-counting strategy. First, it builds a hash map to count the occurrence of each element in the input array. The key insight is that the minimum number of rows needed equals the maximum frequency of any element — if an element appears k times, we need at least k rows to ensure no duplicates within a row.

After determining this maximum frequency (`ga`), the algorithm creates that many empty rows. It then iterates through each row index and, for each row, scans through all unique elements in the hash map. If an element still has remaining occurrences (count > 0), it adds that element to the current row and decrements its count. This process distributes each element's occurrences across different rows, guaranteeing distinctness within each row.

## Complexity

- **Time:** O(n * k)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-16 04:54 UTC
- Runtime: 11 ms
- Memory: 34.5 MB
- Language: C++
