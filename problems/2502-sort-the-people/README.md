# Sort the People

**Difficulty:** Easy
**Tags:** sorting, array, pairing

## Problem

Given two arrays of equal length—one containing names and another containing distinct heights—pair each name with its corresponding height and return the names reordered by decreasing height. The arrays can contain up to 1000 elements, with heights ranging from 1 to 100,000.

## Approach

The solution pairs each name with its height by creating a vector of `pair<int, string>` objects. It iterates through both input arrays simultaneously, storing each height-name pair. After building this vector, it sorts the pairs in ascending order by height (the default comparison for pairs sorts by the first element). The sorted pairs are then traversed to extract the names into an output vector, which is finally reversed to achieve descending height order before returning.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-22 10:16 UTC
- Runtime: 36 ms
- Memory: 25.8 MB
- Language: C++
