# Guess Number Higher or Lower

**Difficulty:** Easy
**Tags:** binary-search, interactive

## Problem

Given a range from 1 to n, find a specific hidden number by repeatedly calling a guess API that returns whether your guess is too high (-1), too low (1), or correct (0). The constraint allows n to be as large as 2^31 - 1, requiring an efficient search strategy to minimize API calls.

## Approach

The solution uses binary search to efficiently locate the target number. It maintains left (l) and right (r) pointers initially set to 0 and n. In each iteration, it calculates the midpoint using `(r-l)/2 + l` to avoid integer overflow. The code calls `guess(mid)` and based on the result: returns mid if the guess is correct (0), shifts the right boundary to mid-1 if the guess is too high (negative return), or shifts the left boundary to mid+1 if the guess is too low (positive return). The loop continues until the boundaries converge on the target number.

## Complexity

- **Time:** O(log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-17 05:50 UTC
- Runtime: 3 ms
- Memory: 7.5 MB
- Language: C++
