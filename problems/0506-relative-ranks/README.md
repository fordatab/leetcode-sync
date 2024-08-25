# Relative Ranks

**Difficulty:** Easy
**Tags:** sorting, array, hash-table

## Problem

Given an array of unique scores representing athletes' performances, assign ranks to each athlete based on their relative performance. The top three performers receive special medal designations ("Gold Medal", "Silver Medal", "Bronze Medal"), while all others receive their numeric rank as a string. Return an array where each position contains the rank of the athlete at that original index.

## Approach

The solution creates pairs of scores with their original indices to maintain the connection between values and positions. It sorts these pairs in descending order by score, which establishes the ranking from best to worst. After sorting, it iterates through the sorted pairs and assigns ranks: the first three positions get medal strings, and all subsequent positions get their numeric rank (position + 1) as a string. Each rank is placed in the result array at the index corresponding to that athlete's original position, ensuring the output maintains the input order.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-25 03:01 UTC
- Runtime: 7 ms
- Memory: 14.7 MB
- Language: C++
