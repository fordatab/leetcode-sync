# Dot Product of Two Sparse Vectors

**Difficulty:** Medium
**Tags:** array, two-pointers, hash-table, design

## Problem

Given two vectors that are mostly zeros (sparse vectors), implement a class that stores them efficiently and computes their dot product. The vectors can have up to 100,000 elements with values between 0 and 100. The key challenge is to avoid iterating through all the zero elements when computing the dot product.

## Approach

The solution stores only the non-zero elements of each vector as pairs of (index, value) in a sorted array. During construction, it iterates through the input vector once and collects all non-zero entries.

For the dot product computation, it uses a two-pointer technique to traverse both sparse representations simultaneously. It compares indices from both vectors: when indices match, it multiplies the corresponding values and adds to the running sum; when indices don't match, it advances the pointer pointing to the smaller index. This continues until one of the vectors is exhausted.

This approach efficiently skips over all the zero elements, only processing positions where at least one vector has a non-zero value, and only multiplying when both vectors have non-zero values at the same index.

## Complexity

- **Time:** O(n + k1 + k2)
- **Space:** O(k)

## Stats

- Submitted: 2025-09-11 00:41 UTC
- Runtime: 120 ms
- Memory: 170 MB
- Language: C++
