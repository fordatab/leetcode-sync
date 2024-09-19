# Find Indices of Stable Mountains

**Difficulty:** Easy
**Tags:** array, iteration, linear-scan

## Problem

Given an array of mountain heights and a threshold value, identify all mountains (except the first one) where the immediately preceding mountain has a height strictly greater than the threshold. The array contains 2 to 100 mountains with heights ranging from 1 to 100, and the threshold ranges from 1 to 100.

## Approach

The solution uses a simple linear scan starting from index 1 (the second mountain) through the end of the array. For each mountain at position `x`, it checks whether the height of the previous mountain at position `x-1` exceeds the threshold. If this condition is met, the current index `x` is added to the output vector. This straightforward iteration handles the constraint that mountain 0 cannot be stable by design, since the loop begins at index 1.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-19 06:04 UTC
- Runtime: 0 ms
- Memory: 27.5 MB
- Language: C++
