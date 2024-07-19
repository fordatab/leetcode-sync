# Lucky Numbers in a Matrix

**Difficulty:** Easy
**Tags:** matrix, hash-table, array

## Problem

Given an m×n matrix where all elements are distinct, find all "lucky numbers" — values that are simultaneously the smallest in their row and the largest in their column. The matrix dimensions range from 1 to 50, and element values can be up to 100,000.

## Approach

The solution uses a frequency-counting approach with three main steps:

1. **Find row minimums**: Iterate through each row and use `min_element` to find the smallest value in that row, storing all row minimums in a vector.

2. **Find column maximums**: For each column index, iterate through all rows to find the maximum value in that column using nested loops and the `max` function, storing all column maximums in a vector.

3. **Identify intersections**: Use a hash map to count occurrences of values. First, increment the count for each column maximum, then increment for each row minimum. Any value appearing more than once (meaning it appears in both the row-minimum and column-maximum sets) is a lucky number.

The key insight is that a lucky number must appear in both the set of row minimums and the set of column maximums, so counting occurrences and filtering for values with count > 1 identifies the answer.

## Complexity

- **Time:** O(m * n)
- **Space:** O(m + n)

## Stats

- Submitted: 2024-07-19 01:49 UTC
- Runtime: 20 ms
- Memory: 15.7 MB
- Language: C++
