# Brightest Position on Street

**Difficulty:** Medium
**Tags:** sweep-line, sorting, array, greedy

## Problem

Given street lamps where each lamp illuminates a range on a number line, find the position with the maximum number of overlapping lamp ranges (brightness). Each lamp at position p with range r lights up positions from p-r to p+r inclusive. Return the smallest position among all positions with maximum brightness.

## Approach

The solution uses a sweep-line algorithm with events. For each lamp, it creates two events: a start event at position (pos - range) with value +1, and an end event at position (pos + range + 1) with value -1. After sorting all events by position, it performs two passes. The first pass computes the maximum brightness by tracking the running sum of event values. The second pass replays the sweep to find the first position where the brightness equals the maximum, returning that position. This works because at any point on the number line, the brightness equals the number of start events minus end events encountered so far.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2025-09-02 03:47 UTC
- Runtime: 75 ms
- Memory: 91.7 MB
- Language: C++
