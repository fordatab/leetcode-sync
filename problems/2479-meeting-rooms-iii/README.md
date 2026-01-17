# Meeting Rooms III

**Difficulty:** Hard
**Tags:** heap, priority-queue, greedy, sorting, simulation

## Problem

Given n meeting rooms numbered 0 to n-1 and a list of meetings with start and end times, allocate meetings to rooms such that each meeting uses the lowest-numbered available room. If no room is available, delay the meeting until one becomes free, maintaining the original duration. Meetings with earlier original start times get priority when rooms become available. Return the room number that hosted the most meetings, with ties broken by the lowest room number. Constraints allow up to 100 rooms and 100,000 meetings with times up to 500,000.

## Approach

The solution sorts all meetings by start time to process them chronologically. It maintains two heaps: a min-heap of free room numbers and a min-heap of occupied rooms paired with their end times. 

For each meeting, the algorithm first frees any rooms whose meetings have ended by the current start time, moving them from the `ends` heap back to the `free` heap. If a free room exists, it assigns the lowest-numbered one (top of `free` heap), increments that room's meeting count, and adds the room with its end time to the `ends` heap.

If no rooms are free, the algorithm takes the room that will become available earliest (top of `ends` heap), increments its counter, and schedules the delayed meeting to start immediately when that room becomes free. The new end time is calculated as the room's earliest availability plus the meeting duration.

Finally, it scans the frequency array to find the room with the maximum meeting count, returning the lowest-numbered room in case of ties.

## Complexity

- **Time:** O(m log m + m log n)
- **Space:** O(n + m)

## Stats

- Submitted: 2026-01-17 07:18 UTC
- Runtime: 1450 ms
- Memory: 160.4 MB
- Language: C++
