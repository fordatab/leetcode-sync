# Equal Row and Column Pairs

**Difficulty:** Medium
**Tags:** hash-table, matrix, string

## Problem

Given an n×n integer matrix, count how many pairs of (row index, column index) exist where the row and column contain exactly the same elements in the same order. The matrix dimensions range from 1×1 to 200×200, with element values up to 10^5.

## Approach

The solution uses a hash table to store serialized representations of all rows. First, it iterates through each row, converting it to a string by concatenating all elements separated by '#' delimiters, and counts occurrences of each unique row pattern in a hash map. Then, it iterates through each column, similarly serializing it to a string, and looks up how many rows match that column pattern in the hash map. The '#' delimiter prevents false matches (e.g., [1,23] vs [12,3]). The total count of matching row-column pairs is accumulated by summing the hash map values for each column string.

## Complexity

- **Time:** O(n²)
- **Space:** O(n²)

## Stats

- Submitted: 2024-08-19 02:58 UTC
- Runtime: 161 ms
- Memory: 49.4 MB
- Language: C++
