# Patching Array

**Difficulty:** Hard
**Tags:** greedy, array, math

## Problem

Given a sorted array of positive integers and a target value n, determine the minimum number of elements that must be added to the array so that every integer from 1 to n (inclusive) can be represented as the sum of some subset of elements. The array can contain duplicates, has at most 1000 elements with values up to 10^4, and n can be as large as 2^31 - 1.

## Approach

The solution maintains a variable `coverage` that tracks the highest consecutive integer reachable from 1 using available elements. Initially, `coverage` is 0, meaning we can form sums in the range [1, 0] (empty range).

The algorithm iterates while `coverage < n`. At each step, if the next array element `nums[i]` is at most `coverage + 1`, we can incorporate it to extend our range to [1, coverage + nums[i]] without gaps. Otherwise, there's a gap at `coverage + 1`, so we patch by adding that value, which doubles our coverage plus one (since we can now form all sums up to `coverage + (coverage + 1)`).

The key insight is that if we can form all sums [1, k], adding a number x ≤ k+1 extends our range to [1, k+x] continuously. When no such number exists in the array, the optimal patch is always k+1 itself, maximizing the extension. This greedy approach ensures the minimum number of patches.

## Complexity

- **Time:** O(m + log n)
- **Space:** O(1)

## Stats

- Submitted: 2025-12-01 12:05 UTC
- Runtime: 0 ms
- Memory: 15.2 MB
- Language: C++
