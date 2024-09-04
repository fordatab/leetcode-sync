# H-Index

**Difficulty:** Medium
**Tags:** counting-sort, array, bucket-sort

## Problem

Given an array where each element represents the citation count of a researcher's paper, find the h-index: the largest value h such that the researcher has at least h papers with h or more citations each. The array can contain up to 5000 papers with citation counts ranging from 0 to 1000.

## Approach

The solution uses a counting sort approach with a bucket array. It creates a bucket array of size n+1 where bucket[i] counts how many papers have exactly i citations, with all papers having n or more citations grouped into bucket[n]. Then it iterates backwards from n to 0, accumulating a running total of papers. At each position x, the running total represents the number of papers with at least x citations. The first position where the count of papers with at least x citations is greater than or equal to x itself is the h-index, since this satisfies the definition that there are h papers with h or more citations.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-04 00:41 UTC
- Runtime: 5 ms
- Memory: 11.2 MB
- Language: C++
