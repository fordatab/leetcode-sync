# Determine if Two Events Have Conflict

**Difficulty:** Easy
**Tags:** string, interval, math

## Problem

Given two time intervals representing events on the same day (each specified by a start and end time in HH:MM format), determine whether the intervals overlap. The intervals are inclusive, meaning if one event ends exactly when another begins, they are considered to have a conflict. Each event is guaranteed to have its start time no later than its end time.

## Approach

The solution uses direct string comparison to check for interval overlap. Since the times are in HH:MM format with zero-padded hours and minutes, lexicographic string comparison correctly reflects chronological ordering.

Two intervals overlap if and only if the first interval's start is not after the second interval's end AND the second interval's start is not after the first interval's end. This is the standard interval overlap condition.

The code implements this by comparing `e1[0] <= e2[1]` (event1 starts before or when event2 ends) and `e2[0] <= e1[1]` (event2 starts before or when event1 ends). If both conditions hold, the events conflict; otherwise they don't.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-17 07:06 UTC
- Runtime: 0 ms
- Memory: 13.1 MB
- Language: C++
