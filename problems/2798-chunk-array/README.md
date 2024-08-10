# Chunk Array

**Difficulty:** Easy
**Tags:** array, reduce, chunking

## Problem

Given an array and a chunk size, partition the array into subarrays where each subarray contains at most the specified number of elements. The final subarray may contain fewer elements if the total array length is not evenly divisible by the chunk size. Empty input arrays should return an empty result.

## Approach

The solution uses `reduce` to build the chunked array incrementally. For each element in the input array, it examines the last subarray in the accumulator. If there is no last subarray yet, or if the last subarray has already reached the specified size, a new subarray containing the current element is created and pushed. Otherwise, the current element is appended to the existing last subarray. The accumulator starts as an empty array and is returned after processing all elements.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-10 21:47 UTC
- Runtime: 59 ms
- Memory: 51.8 MB
- Language: JavaScript
