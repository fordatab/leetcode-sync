# Koko Eating Bananas

**Difficulty:** Medium
**Tags:** binary-search, array, greedy

## Problem

Given n piles of bananas and h hours, find the minimum eating speed k such that all bananas can be consumed within h hours. Each hour, k bananas are eaten from a single pile (or the entire pile if it contains fewer than k bananas), and at most one pile can be partially or fully consumed per hour. The constraint is that the number of piles is at most h, and both pile sizes and h can be up to 10^9.

## Approach

This solution uses binary search to find the minimum eating speed. The search space ranges from 1 (minimum possible speed) to the maximum pile size (eating the largest pile in one hour). For each candidate speed in the middle of the range, the code calculates the total hours needed by iterating through all piles and computing the ceiling of pile_size/speed (implemented as pile_size/speed + 1 if there's a remainder). If the total hours exceed h, the speed is too slow and the search continues in the upper half; otherwise, the speed might work and the search continues in the lower half. The binary search terminates when the pointers cross, returning r + 1 as the minimum valid speed.

## Complexity

- **Time:** O(n log m)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-02 05:56 UTC
- Runtime: 27 ms
- Memory: 21.3 MB
- Language: C++
