# Maximum Number of Events That Can Be Attended

**Difficulty:** Medium
**Tags:** greedy, heap, priority-queue, sorting, simulation

## Problem

Given an array of events where each event has a start day and end day, find the maximum number of events you can attend if you can only attend one event per day and must attend on a day within each event's valid range. The events array can contain up to 100,000 events, and days range from 1 to 100,000.

## Approach

The solution uses a greedy approach with a min-heap to maximize event attendance. First, events are sorted by start day. Then, the algorithm iterates through each day from 1 to the last possible day. For each day, it adds all events starting on that day to a min-heap (priority queue) ordered by end day. Before making a choice, it removes all expired events (those whose end day is before the current day) from the heap. If any valid events remain in the heap, it attends the one ending soonest (the heap's top element) by removing it and incrementing the counter. This greedy strategy of always choosing the event that expires soonest ensures we leave room for future events with later deadlines.

## Complexity

- **Time:** O(n log n + d log n)
- **Space:** O(n)

## Stats

- Submitted: 2025-11-26 03:45 UTC
- Runtime: 68 ms
- Memory: 75 MB
- Language: C++
