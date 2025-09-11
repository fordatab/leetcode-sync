# Design Underground System

**Difficulty:** Medium
**Tags:** hash-table, design, nested-map, data-structure

## Problem

Design a system that tracks passengers checking in and out of subway stations at specific times. The system must support three operations: recording when a passenger enters a station, recording when they exit a station, and computing the average travel time between any two stations based on all completed trips. Each passenger can only be checked into one station at a time, and all check-in times occur before their corresponding check-out times.

## Approach

The solution uses two hash maps to track state. The `customers` map stores each currently-traveling passenger's ID along with their entry station and entry time as a pair. When a passenger checks in, their information is stored in this map. 

The nested map structure `m` organizes all completed trips: the outer map is keyed by start station, the inner map by end station, and the value is a vector storing pairs of (start_time, end_time) for each completed journey on that route.

When a passenger checks out, the code retrieves their check-in details from `customers`, appends the (start_time, end_time) pair to the appropriate route in the nested map, and removes them from the active customers map.

To calculate average time, the code iterates through all recorded trips for the given route, sums the differences between end and start times, and divides by the trip count. This approach stores every individual trip rather than maintaining running totals, which increases memory usage but simplifies the implementation.

## Complexity

- **Time:** O(1) for checkIn and checkOut, O(k) for getAverageTime where k is the number of trips between the two stations
- **Space:** O(n + m) where n is the number of active customers and m is the total number of completed trips

## Stats

- Submitted: 2025-09-11 05:18 UTC
- Runtime: 34 ms
- Memory: 67 MB
- Language: C++
