# Circular Array Loop

**Difficulty:** Medium
**Tags:** two-pointers, fast-slow-pointers, cycle-detection, array

## Problem

Given a circular array of non-zero integers where each element indicates how many steps to move forward (positive) or backward (negative), determine if there exists a valid cycle. A valid cycle must have length greater than 1 and all movements in the same direction (all forward or all backward). The array wraps around, so moving past the end returns to the beginning and vice versa.

## Approach

The solution uses Floyd's cycle detection algorithm (tortoise and hare) for each starting index. For each position, it runs two pointers at different speeds (slow moves one step, fast moves two steps) until they meet, detecting if a cycle exists. Once a meeting point is found, it runs the cycle detection again while checking two conditions: tracking whether all values in the cycle are positive or all negative (using `pos` and `neg` flags), and counting the cycle length. The cycle is valid only if the length exceeds 1 and all movements are unidirectional (exactly one of `pos` or `neg` remains true, checked via XOR). The modulo helper function handles the circular wraparound by ensuring negative indices map correctly to positive array positions.

## Complexity

- **Time:** O(n²)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-20 10:30 UTC
- Runtime: 44 ms
- Memory: 9.2 MB
- Language: C++
