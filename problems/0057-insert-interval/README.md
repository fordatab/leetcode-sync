# Insert Interval

**Difficulty:** Medium
**Tags:** array, interval-merging, greedy, sorting

## Problem

Given a sorted array of non-overlapping intervals and a new interval to insert, merge the new interval with any overlapping existing intervals and return the resulting sorted list. The input intervals are sorted by start time, contain up to 10,000 intervals, and all values are bounded by 10^5. The solution must handle merging when the new interval overlaps one or more existing intervals.

## Approach

The solution performs a single linear pass through the existing intervals, classifying each interval into one of three categories:

1. **Non-overlapping before**: If an existing interval ends before the new interval starts (`intervals[i][1] < newStart`), it's added directly to the result as it can't overlap.

2. **Non-overlapping after**: If an existing interval starts after the new interval ends (`intervals[i][0] > newEnd`), the new interval (possibly already merged) is added to the result, followed by all remaining intervals copied in bulk, and the function returns immediately.

3. **Overlapping**: If neither of the above conditions holds, the interval overlaps with the new interval. The new interval's bounds are expanded by taking the minimum start and maximum end between the two intervals.

After processing all intervals, if the new interval hasn't been inserted yet (meaning no interval started after it), it's appended to the result. This handles the case where the new interval comes at the end.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-17 05:26 UTC
- Runtime: 17 ms
- Memory: 20.8 MB
- Language: C++
