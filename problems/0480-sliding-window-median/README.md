# Sliding Window Median

**Difficulty:** Hard
**Tags:** sliding-window, two-heaps, multiset, median-finding, ordered-set

## Problem

Given an array of integers and a window size k, compute the median for each contiguous subarray of size k as the window slides from left to right. For odd-sized windows, the median is the middle element; for even-sized windows, it's the average of the two middle elements. The array can have up to 100,000 elements, and values range from -2³¹ to 2³¹-1.

## Approach

The solution maintains two multisets to simulate a two-heap structure for finding the running median. The `small` multiset holds the smaller half of the current window (acts like a max-heap by accessing the largest via `rbegin()`), while `large` holds the larger half (acts like a min-heap by accessing the smallest via `begin()`).

For each element added to the window:
1. Insert it into `small`, then immediately move the largest element from `small` to `large`
2. Rebalance so `small` has equal or one more element than `large`
3. Once the window exceeds size k, remove the oldest element from whichever multiset contains it
4. Re-rebalance if necessary after removal
5. When the window reaches exactly size k, compute the median: if `small` has more elements (odd k), use its maximum; otherwise (even k), average the maximum of `small` and minimum of `large`

The multisets allow efficient insertion, deletion, and access to boundary elements, maintaining sorted order throughout the sliding process.

## Complexity

- **Time:** O(n log k)
- **Space:** O(k)

## Stats

- Submitted: 2026-01-18 08:37 UTC
- Runtime: 115 ms
- Memory: 62.6 MB
- Language: C++
