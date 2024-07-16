# Number of Good Pairs

**Difficulty:** Easy
**Tags:** hash-table, counting, combinatorics, array

## Problem

Given an array of integers, count how many pairs of indices (i, j) exist where i < j and the elements at those positions are equal. The array has length between 1 and 100, with element values ranging from 1 to 100.

## Approach

The solution uses a frequency-counting approach with a hash map. It first iterates through the array once to count the occurrences of each distinct value. Then, for each value that appears multiple times, it calculates the number of pairs that can be formed using the combination formula C(n, 2) = n*(n-1)/2, where n is the frequency of that value. This formula gives the number of ways to choose 2 indices from n occurrences. Finally, it sums up the pair counts for all distinct values to get the total number of good pairs.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-16 10:04 UTC
- Runtime: 0 ms
- Memory: 9 MB
- Language: C++
