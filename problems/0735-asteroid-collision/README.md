# Asteroid Collision

**Difficulty:** Medium
**Tags:** stack, array, simulation

## Problem

Given an array of integers representing asteroids where positive values move right and negative values move left, simulate collisions where smaller asteroids explode, equal-sized asteroids both explode, and asteroids moving in the same direction never collide. The array can contain up to 10,000 asteroids with absolute values up to 1000. Return the final state after all collisions resolve.

## Approach

The solution uses a stack to track surviving asteroids moving right. For each asteroid in the input:

- If it's moving right (positive) or the stack is empty, it's pushed onto the stack
- If it's moving left (negative) and encounters right-moving asteroids on the stack, collisions are resolved:
  - If sizes are equal, the stack asteroid is popped and the current asteroid is discarded
  - If the left-moving asteroid is smaller, it's discarded without being pushed
  - If the left-moving asteroid is larger, the stack asteroid is popped and collision checking continues
- A boolean flag `to_push` tracks whether the current asteroid survives

After processing all asteroids, the stack contents are popped into a vector and reversed to restore the correct left-to-right order. The key insight is that only right-moving asteroids can remain on the stack to collide with future left-moving ones.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-21 08:52 UTC
- Runtime: 28 ms
- Memory: 20.8 MB
- Language: C++
