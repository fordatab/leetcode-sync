# Find Score of an Array After Marking All Elements

**Difficulty:** Medium
**Tags:** heap, priority-queue, hash-set, greedy, simulation

## Problem

Given an array of positive integers, repeatedly select the smallest unmarked element (breaking ties by choosing the leftmost index), add it to a running score, then mark that element and its two neighbors (if they exist). Continue until all elements are marked and return the total score. The array can contain up to 100,000 elements with values up to 1,000,000.

## Approach

The solution uses a min-heap (priority queue) to efficiently retrieve elements in ascending order by value, with index as a tiebreaker. All elements are initially inserted into the heap as (value, index) pairs. An unordered set tracks which indices have been marked.

The algorithm repeatedly extracts the minimum element from the heap. If that index is already marked, it's skipped. Otherwise, its value is added to the score, and the element itself plus its left and right neighbors (if within bounds) are added to the marked set.

The loop continues until the marked set contains all indices (size equals array length). This approach avoids repeatedly scanning the array for the next unmarked minimum, trading space for time by maintaining both the heap and the set.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2026-04-21 20:48 UTC
- Runtime: 282 ms
- Memory: 150.4 MB
- Language: C++
