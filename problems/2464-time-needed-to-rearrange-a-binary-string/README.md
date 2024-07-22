# Time Needed to Rearrange a Binary String

**Difficulty:** Medium
**Tags:** string, simulation, two-pointers

## Problem

Given a binary string, you must repeatedly perform a transformation where all occurrences of the substring "01" are simultaneously replaced with "10". The process continues until no "01" patterns remain. Return the total number of transformation rounds needed. The string has length up to 1000, and each character is either '0' or '1'.

## Approach

The solution uses a simulation approach that directly models the transformation process described in the problem. It maintains a boolean flag to track whether any swaps occurred in the current round. In each iteration, it scans through the string from left to right, and whenever it finds a "01" pattern, it swaps the characters to "10" and increments the loop counter by one extra position (to skip the just-swapped '0' and avoid re-processing it in the same round). After each complete scan, if at least one swap was made, the second counter is incremented and another round begins. The process terminates when a full scan produces no swaps, meaning all ones have bubbled to the left of all zeros.

## Complexity

- **Time:** O(n²)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-22 23:44 UTC
- Runtime: 56 ms
- Memory: 8.2 MB
- Language: C++
