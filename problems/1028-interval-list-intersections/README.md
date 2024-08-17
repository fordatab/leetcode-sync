# Interval List Intersections

**Difficulty:** Medium
**Tags:** two-pointers, intervals, array, sorting

## Problem

Given two sorted lists of non-overlapping closed intervals, find all intervals that appear in both lists (their intersection). Each list can contain up to 1000 intervals, with endpoint values ranging from 0 to 10^9. The intervals within each list are guaranteed to be disjoint and sorted by start time.

## Approach

The solution uses a two-pointer technique to traverse both interval lists simultaneously. It maintains pointers `i` and `j` for the first and second lists respectively. At each step, it checks if the current intervals from both lists overlap:

- If the first interval ends before the second begins, advance pointer `i`
- If the second interval ends before the first begins, advance pointer `j`
- If they overlap, compute the intersection by taking the maximum of the start points and the minimum of the end points. The intersection's end point is determined by whichever interval ends first, and that interval's pointer is then advanced.

The key insight is that since both lists are sorted and disjoint within themselves, we only need to compare the current pair of intervals at each step. When intervals overlap, we advance the pointer of whichever interval ends earlier, as it cannot intersect with any future intervals from the other list.

## Complexity

- **Time:** O(n + m)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-17 06:28 UTC
- Runtime: 23 ms
- Memory: 22.4 MB
- Language: C++
