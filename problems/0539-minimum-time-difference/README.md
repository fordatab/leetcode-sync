# Minimum Time Difference

**Difficulty:** Medium
**Tags:** sorting, array, string-parsing, greedy

## Problem

Given a list of time points in 24-hour "HH:MM" format, find the smallest difference in minutes between any pair of times. The list can contain up to 20,000 time points, and times wrap around midnight (so 23:59 and 00:00 are only 1 minute apart).

## Approach

The solution converts each time string to total minutes since midnight by parsing the hours and minutes, then multiplying hours by 60 and adding the minutes. All converted times are stored in a vector and sorted in ascending order.

After sorting, the minimum difference is found by checking consecutive pairs of times. For each adjacent pair, the difference is simply the later time minus the earlier time. The special case handled is the wraparound between the last time of the day and the first time: this circular difference is calculated as 1440 (total minutes in a day) minus the difference between the last and first sorted times.

The algorithm tracks the minimum across all these differences and returns it. The sorting ensures we only need to check adjacent times rather than all possible pairs.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2025-09-02 00:35 UTC
- Runtime: 53 ms
- Memory: 18.1 MB
- Language: C++
