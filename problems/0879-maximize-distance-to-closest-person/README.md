# Maximize Distance to Closest Person

**Difficulty:** Medium
**Tags:** array, two-pointers, greedy

## Problem

Given a binary array representing seats where 1 indicates an occupied seat and 0 an empty one, find the maximum distance to the nearest occupied seat if you choose the optimal empty seat to sit in. The array has at least one occupied and one empty seat, and can contain up to 20,000 elements.

## Approach

The solution uses a two-pointer sliding window approach to track consecutive stretches of empty seats between occupied ones. It maintains a left pointer `l` at the most recent occupied seat and scans with a right pointer `r`. When encountering an occupied seat, it calculates the distance to the closest person: for the first occupied seat found, the distance is simply `r` (covering leading empty seats); for subsequent occupied seats, the maximum distance in the middle section is `(r - l) / 2` (integer division, representing the midpoint of the gap). After processing all seats, it also checks the trailing empty seats by computing `seats.size() - (l + 1)`, which gives the distance from the last occupied seat to the end. The maximum across all these cases is returned.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2025-11-26 02:36 UTC
- Runtime: 0 ms
- Memory: 22.9 MB
- Language: C++
