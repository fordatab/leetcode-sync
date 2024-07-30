# Maximum Product Subarray

**Difficulty:** Medium
**Tags:** dynamic-programming, array, greedy

## Problem

Find a contiguous subarray within an integer array that yields the maximum product of its elements, and return that product. The array can contain positive numbers, negative numbers, and zeros, with values ranging from -10 to 10 and lengths up to 20,000 elements. The result is guaranteed to fit in a 32-bit integer.

## Approach

This solution uses a dynamic programming approach that tracks both the maximum and minimum product ending at each position. It maintains two running values: `curMax` (maximum product ending at current position) and `curMin` (minimum product ending at current position).

For each element, the algorithm computes three candidates: the current element alone, the current element times the previous maximum, and the current element times the previous minimum. The minimum tracking is crucial because a negative number can turn a minimum (most negative) product into a maximum when multiplied.

The code stores `curMax * n` in a temporary variable before updating both `curMax` and `curMin`, ensuring that both updates use the old value of `curMax`. After processing each element, it updates the global result with the current maximum. The solution uses `double` precision for intermediate calculations to avoid potential overflow during multiplication, then casts back to `int` for the final result.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-30 03:04 UTC
- Runtime: 5 ms
- Memory: 16.6 MB
- Language: C++
