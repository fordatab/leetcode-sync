# First Bad Version

**Difficulty:** Easy
**Tags:** binary-search, interactive

## Problem

Given n sequential versions numbered 1 to n where all versions after the first bad version are also bad, find the first bad version using an API that checks if a given version is bad. The constraint is to minimize API calls, with n potentially as large as 2^31 - 1.

## Approach

The solution uses binary search to efficiently locate the first bad version. It maintains a search range with left pointer `l` starting at 0 and right pointer `r` starting at n. In each iteration, it calculates the midpoint using `(r - l)/2 + l` to avoid integer overflow. If the middle version is bad, it means the first bad version is at or before mid, so the right boundary moves to mid. If the middle version is good, the first bad version must be after mid, so the left boundary moves to mid + 1. The search continues until the pointers converge, at which point `l` points to the first bad version.

## Complexity

- **Time:** O(log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-24 05:03 UTC
- Runtime: 2 ms
- Memory: 7.7 MB
- Language: C++
