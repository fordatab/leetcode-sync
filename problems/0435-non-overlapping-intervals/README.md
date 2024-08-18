# Non-overlapping Intervals

**Difficulty:** Medium
**Tags:** greedy, sorting, intervals

## Problem

Given a collection of intervals where each interval has a start and end point, determine the minimum number of intervals that must be removed so that no two remaining intervals overlap. Intervals that only touch at a boundary point (like [1,2] and [2,3]) are considered non-overlapping. The input can contain up to 100,000 intervals with coordinates ranging from -50,000 to 50,000.

## Approach

The solution uses a greedy algorithm with interval sorting. First, it sorts all intervals by their start position (using the default lexicographic comparison). Then it iterates through the sorted intervals while tracking the end position of the previously kept interval.

When examining each interval, if its start overlaps with the previous interval's end (start < previous_end), an overlap is detected and one interval must be removed. The greedy choice is to keep the interval with the smaller end position, as this leaves more room for future intervals. The removal counter increments and the tracked end is updated to the minimum of the two overlapping intervals' ends.

If no overlap exists (current start >= previous end), the current interval is kept and becomes the new reference point. This greedy approach works because by always favoring intervals that end earlier, we maximize the remaining space for subsequent intervals in the sorted sequence.

## Complexity

- **Time:** O(n log n)
- **Space:** O(log n)

## Stats

- Submitted: 2024-08-18 04:17 UTC
- Runtime: 265 ms
- Memory: 93.6 MB
- Language: C++
