# Design Hit Counter

**Difficulty:** Medium
**Tags:** design, queue, deque, sliding-window

## Problem

Design a data structure that tracks hits (events) and can count how many hits occurred within the last 300 seconds from any given timestamp. The hit() method records an event at a specific timestamp, while getHits() returns the count of hits in the 5-minute window ending at the query timestamp. All timestamps arrive in non-decreasing order, and there can be at most 300 total calls to both methods combined.

## Approach

The solution uses a double-ended queue (deque) to maintain timestamps of all hits in chronological order. When a hit is recorded, the timestamp is simply appended to the back of the deque since inputs arrive in sorted order. When getHits() is called, it removes all timestamps from the front of the deque that fall outside the 300-second window (timestamps <= query_time - 300), then returns the size of the remaining deque. This lazy cleanup strategy means expired hits are only removed when needed during a getHits() query, not proactively after each hit.

## Complexity

- **Time:** O(1) for hit, O(n) worst-case for getHits where n is the number of hits in the deque
- **Space:** O(n) where n is the number of hits stored

## Stats

- Submitted: 2025-11-30 08:32 UTC
- Runtime: 0 ms
- Memory: 10.6 MB
- Language: C++
