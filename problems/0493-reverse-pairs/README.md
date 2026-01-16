# Reverse Pairs

**Difficulty:** Hard
**Tags:** divide-and-conquer, merge-sort, two-pointers, array

## Problem

Count pairs of indices (i, j) where i < j and the element at index i is strictly greater than twice the element at index j. The input is an integer array of up to 50,000 elements with values in the 32-bit signed integer range.

## Approach

The solution uses a modified merge sort to count reverse pairs efficiently. During the divide-and-conquer process, it recursively sorts the left and right halves, then counts cross-boundary pairs before merging.

The key insight is that once both halves are sorted, we can count valid pairs between them in linear time using a two-pointer technique. For each element in the left half, we advance a pointer through the right half to find how many elements satisfy the condition (left element > 2 * right element). Because the right half is sorted, all elements from the starting position up to the pointer position form valid pairs.

After counting, the solution performs a standard merge operation to combine the sorted halves, maintaining the sorted property for subsequent levels of recursion. The running count is accumulated in a class member variable across all recursive calls.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2026-01-16 21:19 UTC
- Runtime: 199 ms
- Memory: 112.5 MB
- Language: C++
