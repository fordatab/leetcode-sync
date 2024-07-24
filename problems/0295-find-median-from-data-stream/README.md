# Find Median from Data Stream

**Difficulty:** Hard
**Tags:** heap, priority-queue, design, data-stream, two-heaps

## Problem

Design a data structure that supports adding integers from a stream and efficiently computing the median of all elements seen so far. The median is the middle element in sorted order, or the average of the two middle elements if the count is even. The structure must handle up to 50,000 operations with integer values between -100,000 and 100,000.

## Approach

This solution uses two heaps to maintain the streaming numbers in a way that allows O(log n) insertions and O(1) median retrieval. A max-heap `l` stores the smaller half of the numbers, and a min-heap `r` stores the larger half. The heaps are kept balanced so their sizes differ by at most one.

When adding a number, if the heaps are equal in size, the code decides whether to add it to `l` directly or to move `r`'s smallest element to `l` and insert the new number into `r`. If `l` is larger, the code either moves `l`'s largest to `r` and inserts the new number into `l`, or directly inserts into `r`. This maintains the invariant that all elements in `l` are less than or equal to all elements in `r`.

To find the median, if the heaps have equal size, the median is the average of the tops of both heaps. Otherwise, it's the top of whichever heap is larger. The code uses a careful averaging formula `l.top() + (r.top() - l.top()) / 2.0` to avoid potential overflow issues.

## Complexity

- **Time:** O(log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-24 05:12 UTC
- Runtime: 260 ms
- Memory: 122 MB
- Language: C++
