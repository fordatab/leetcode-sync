# Largest Rectangle in Histogram

**Difficulty:** Hard
**Tags:** stack, monotonic-stack, histogram, array

## Problem

Given an array of bar heights representing a histogram where each bar has width 1, find the maximum rectangular area that can be formed. The array can contain up to 10^5 elements with heights ranging from 0 to 10^4. The challenge is to efficiently identify the largest rectangle that fits within the histogram's boundaries.

## Approach

The solution uses a monotonic stack to track bars in non-decreasing height order. A sentinel value (0) is appended to the input to force processing of all remaining bars. As we iterate through the histogram, when encountering a bar shorter than the stack top, we pop taller bars and calculate the maximum rectangle that can be formed using each popped bar's height. For each popped bar, the width extends from its original index to the current position. The key insight is that when a bar is popped, we know it cannot extend further right (blocked by the current shorter bar), so we can calculate its maximum rectangle area. Each bar stores both its index and height as a pair. After popping, we push the current bar with an adjusted index that accounts for the bars we just processed, allowing rectangles to extend leftward through previously popped taller bars.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-06-29 10:49 UTC
- Runtime: 327 ms
- Memory: 82.1 MB
- Language: C++
