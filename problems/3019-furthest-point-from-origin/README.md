# Furthest Point From Origin

**Difficulty:** Easy
**Tags:** string, greedy, counting, math

## Problem

Given a string representing moves on a number line starting at zero, where 'L' means move left, 'R' means move right, and '_' can be either direction, find the maximum distance from the origin achievable. The string length is between 1 and 50, and consists only of 'L', 'R', and '_' characters.

## Approach

The solution counts the occurrences of each character type using a tuple to store three counters: left moves, right moves, and wildcards. It iterates through the string once, incrementing the appropriate counter for each character.

After counting, it calculates the net displacement (left count minus right count). The key insight is that to maximize distance from origin, all wildcard moves should be assigned to amplify the existing displacement direction.

If the net displacement is negative (more right moves), the wildcards should all go right; if positive or zero (more left moves or equal), they should all go left. The final answer is the absolute value of the net displacement plus all wildcard moves, which simplifies to `abs(left - right) + wildcards`.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-10 00:50 UTC
- Runtime: 0 ms
- Memory: 9.1 MB
- Language: C++
