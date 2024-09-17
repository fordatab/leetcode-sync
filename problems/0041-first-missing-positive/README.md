# First Missing Positive

**Difficulty:** Hard
**Tags:** array, cyclic-sort, in-place

## Problem

Find the smallest positive integer (starting from 1) that does not appear in an unsorted integer array. The array can contain negative numbers, zeros, and duplicates, with up to 100,000 elements ranging from -2³¹ to 2³¹-1. The challenge requires O(n) time complexity and O(1) auxiliary space.

## Approach

The solution uses **cyclic sort** to place each positive integer in its "correct" position within the array. Specifically, if a number `x` is in the valid range [1, n], it should ideally be at index `x-1`.

The algorithm performs two passes:

1. **Placement pass**: For each position, repeatedly swap the current element to its target index (value `x` goes to index `x-1`) until either the element is out of range [1, n], already in the correct position, or the target position already holds the correct value. This ensures all valid positive integers are moved to their ideal locations.

2. **Detection pass**: Scan the array from left to right. The first index `i` where `nums[i] != i+1` reveals that the positive integer `i+1` is missing. If all positions [0, n-1] contain their correct values, then `n+1` is the answer.

The in-place swapping avoids extra space, and each element is moved at most once to its final position, keeping the time complexity linear.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-17 00:14 UTC
- Runtime: 64 ms
- Memory: 53.9 MB
- Language: C++
