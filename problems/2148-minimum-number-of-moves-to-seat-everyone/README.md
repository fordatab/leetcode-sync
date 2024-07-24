# Minimum Number of Moves to Seat Everyone

**Difficulty:** Easy
**Tags:** sorting, greedy, array

## Problem

Given two arrays of equal length representing seat positions and student positions on a line, find the minimum total distance students must move so that each student occupies a distinct seat. Each move shifts a student one unit left or right, and multiple seats or students may start at the same position. Array lengths are at most 100, and all positions range from 1 to 100.

## Approach

The solution uses a greedy matching strategy based on sorting. First, both the `seats` and `students` arrays are sorted in ascending order. Then, the algorithm pairs each student with the seat at the corresponding index in the sorted arrays—the smallest-positioned student goes to the smallest-positioned seat, the second-smallest to the second-smallest, and so on. For each pairing, it calculates the absolute difference (distance) between the student's current position and their assigned seat position, summing these distances to get the total number of moves. This greedy pairing minimizes the total movement because matching sorted positions avoids crossing movements and ensures optimal assignment.

## Complexity

- **Time:** O(n log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-24 19:58 UTC
- Runtime: 7 ms
- Memory: 21.4 MB
- Language: C++
