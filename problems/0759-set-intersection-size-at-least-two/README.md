# Set Intersection Size At Least Two

**Difficulty:** Hard
**Tags:** greedy, sorting, intervals, hash-table

## Problem

Given a collection of intervals where each interval is represented by a start and end integer, find the minimum size of a set such that every interval contains at least two elements from that set. The intervals can have up to 3000 elements, and the integer values can range from 0 to 10^8.

## Approach

The solution uses a greedy approach with custom sorting. First, intervals are sorted by their end points in ascending order, with ties broken by placing intervals with larger start points first. This ordering ensures that when processing intervals, we prioritize those that end earliest and are most restrictive.

For each interval, the algorithm checks how many elements from the current result set already fall within that interval's range. If no elements are present (count is 0), it adds the two largest possible values: the interval's end point and one less than the end point. If exactly one element is present, it adds just the end point.

The core insight is that by always choosing elements at the right end of each interval (greedily selecting the largest valid values), we maximize the chance that these elements will also satisfy subsequent intervals, since the intervals are processed in order of increasing end points. The final answer is the size of the accumulated set.

## Complexity

- **Time:** O(n² + n log n)
- **Space:** O(n)

## Stats

- Submitted: 2026-01-16 04:12 UTC
- Runtime: 171 ms
- Memory: 25.3 MB
- Language: C++
