# My Calendar I

**Difficulty:** Medium
**Tags:** binary-search, sorted-array, interval-overlap, design

## Problem

Design a calendar system that tracks booked time intervals and prevents double bookings. Each event is represented as a half-open interval [start, end), and a booking request should be accepted only if it doesn't overlap with any existing event. The system must handle up to 1000 booking requests with timestamps up to 10^9.

## Approach

The solution maintains a sorted vector of booked intervals. For each booking request:

- Use binary search (`lower_bound`) to find the first event whose start time is greater than or equal to the requested start time. This efficiently locates where the new event would fit in the sorted sequence.

- Check for overlap with the found event (if it exists) by verifying that the new event's end time doesn't extend into the next event's start time.

- Check for overlap with the previous event (if it exists) by verifying that the previous event's end time doesn't extend into the new event's start time.

- If no overlaps are detected, insert the new interval at the found position, maintaining the sorted order. Otherwise, reject the booking.

This approach keeps events sorted by start time, allowing efficient overlap detection by only checking immediate neighbors.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2025-12-04 07:51 UTC
- Runtime: 11 ms
- Memory: 42.9 MB
- Language: C++
