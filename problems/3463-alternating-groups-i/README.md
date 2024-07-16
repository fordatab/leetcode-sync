# Alternating Groups I

**Difficulty:** Easy
**Tags:** array, sliding-window, circular-array

## Problem

Given a circular array of tiles colored either red (0) or blue (1), count how many three-consecutive-tile groups have alternating colors, meaning the middle tile differs from both its neighbors. Since the array is circular, the last and first elements are adjacent.

## Approach

The solution uses a sliding window of three indices (x, y, z) that moves through the array. For each position, it checks two patterns: whether the first and third tiles are both blue (1) with a red (0) middle tile, or both red (0) with a blue (1) middle tile. The modulo operator handles the circular wraparound so that indices beyond the array length correctly reference the beginning of the array. The window slides by incrementing all three indices simultaneously, and each valid alternating pattern increments the counter.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-16 06:42 UTC
- Runtime: 12 ms
- Memory: 26.6 MB
- Language: C++
