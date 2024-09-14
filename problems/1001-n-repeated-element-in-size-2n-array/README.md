# N-Repeated Element in Size 2N Array

**Difficulty:** Easy
**Tags:** array, pigeonhole-principle, sliding-window, pattern-matching

## Problem

Given an array of length 2n containing n+1 unique values where exactly one element appears n times and all others appear once, find and return the element that appears n times. The array length ranges from 4 to 10000, and elements are between 0 and 10000.

## Approach

The solution uses a sliding window observation: since one element appears n times in an array of size 2n (meaning it appears half the time), by the pigeonhole principle, there must be at least one occurrence where two copies of the repeated element are within distance 2 of each other.

The code iterates through the array checking if each element equals either its immediate neighbor (i+1) or the element two positions ahead (i+2). When such a match is found, that element must be the one repeated n times, so it's returned immediately.

If the loop completes without finding a match (which mathematically can only happen when the repeated element is at the last position and one of the earlier positions), the last element is returned as a fallback. This handles the edge case where the pattern isn't detected within the main loop iteration bounds.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-14 05:03 UTC
- Runtime: 23 ms
- Memory: 27.4 MB
- Language: C++
