# Robot Return to Origin

**Difficulty:** Easy
**Tags:** string, simulation, math

## Problem

Given a string representing a robot's movement sequence on a 2D plane starting from origin (0,0), determine whether the robot returns to the origin after executing all moves. Each character in the string is one of four directions: 'U' (up), 'D' (down), 'L' (left), or 'R' (right). The input string can be up to 20,000 characters long.

## Approach

The solution simulates the robot's movement by maintaining its position as a pair of coordinates. Starting from (0, 0), it iterates through each character in the moves string and updates the position accordingly:

- 'U' increments the y-coordinate (second value)
- 'D' decrements the y-coordinate
- 'R' increments the x-coordinate (first value)
- 'L' decrements the x-coordinate

After processing all moves, the solution checks if both coordinates are zero, indicating the robot has returned to the origin. The switch statement provides an efficient way to handle each of the four possible move types.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-10 00:43 UTC
- Runtime: 9 ms
- Memory: 9.4 MB
- Language: C++
