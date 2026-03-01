# Minimum Operations to Make Median of Array Equal to K

**Difficulty:** Medium
**Tags:** sorting, greedy, median, array

## Problem

Given an integer array and a target value k, determine the minimum number of increment or decrement operations (each changing an element by 1) needed so that the median of the array equals k. The median is defined as the middle element when the array is sorted; if there are two middle elements, the larger index is chosen. Array elements can be between 1 and 10^9, and the array can contain up to 200,000 elements.

## Approach

The solution first sorts the array to identify the median position, which is at index n/2 for an array of size n. It then iterates through all elements and calculates the required operations based on their position relative to the median:

- For elements before the median (left half), if they exceed k, they must be decreased to at most k to avoid pushing the median above k. The operations needed are max(num - k, 0).
- For elements after the median (right half), if they are below k, they must be increased to at least k to avoid pulling the median below k. The operations needed are max(k - num, 0).
- For the median element itself, it must be changed to exactly k, requiring abs(k - num) operations.

The total operations are summed and returned. This greedy approach ensures that all elements are adjusted to allow the median to become k while minimizing total changes.

## Complexity

- **Time:** O(n log n)
- **Space:** O(1)

## Stats

- Submitted: 2026-03-01 02:27 UTC
- Runtime: 1384 ms
- Memory: 89.9 MB
- Language: C++
