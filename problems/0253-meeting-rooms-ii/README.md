# Meeting Rooms II

**Difficulty:** Medium
**Tags:** sweep-line, sorting, greedy, intervals

## Problem

Given a collection of meeting time intervals where each interval has a start and end time, determine the minimum number of conference rooms needed to accommodate all meetings. The intervals can have up to 10,000 meetings with times ranging from 0 to 1,000,000.

## Approach

The solution uses an event-based sweep line algorithm. It converts each meeting interval into two events: a start event (marked with +1) and an end event (marked with -1). All events are collected in a vector of pairs where each pair contains a timestamp and its event type.

The events are then sorted by timestamp. When timestamps are equal, the custom comparator ensures start events (+1) come before end events (-1), which is crucial for correctly handling meetings that end exactly when another begins.

Finally, the algorithm sweeps through all events in chronological order, maintaining a running count of active meetings. Each start event increments the count, and each end event decrements it. The maximum count encountered during this sweep represents the peak number of simultaneous meetings, which is the minimum number of rooms required.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2025-08-31 01:49 UTC
- Runtime: 0 ms
- Memory: 16.6 MB
- Language: C++
