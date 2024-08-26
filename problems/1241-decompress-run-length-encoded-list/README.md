# Decompress Run-Length Encoded List

**Difficulty:** Easy
**Tags:** array, simulation, run-length-encoding

## Problem

Given an array of integers representing run-length encoded data, decode it by treating consecutive pairs of elements as [frequency, value]. For each pair at positions [2i, 2i+1], append the value 2i+1 exactly 2i times to the output. The input array has even length between 2 and 100, with all values between 1 and 100.

## Approach

The solution uses a straightforward nested-loop approach to decode the run-length encoded list. The outer loop iterates through the input array with a step of 2, treating each pair of elements as a frequency-value pair. For each pair, the inner loop runs `nums[x]` times (the frequency), appending `nums[x+1]` (the value) to the output vector in each iteration. This directly implements the decompression by expanding each encoded pair into its full representation.

## Complexity

- **Time:** O(n * m)
- **Space:** O(k)

## Stats

- Submitted: 2024-08-26 06:28 UTC
- Runtime: 4 ms
- Memory: 11.9 MB
- Language: C++
