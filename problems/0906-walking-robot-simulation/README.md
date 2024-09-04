# Walking Robot Simulation

**Difficulty:** Medium
**Tags:** simulation, hash-table, geometry

## Problem

Simulate a robot navigating an infinite 2D grid starting at the origin facing north. The robot processes a sequence of commands: -1 and -2 rotate it right or left 90 degrees, while positive integers 1-9 move it forward that many units step-by-step. If the robot encounters an obstacle during movement, it stops before hitting it and proceeds to the next command. Track the maximum squared Euclidean distance from the origin throughout the entire path.

## Approach

The solution simulates the robot's movement step-by-step. It uses a hash set to store obstacle positions, encoding each (x, y) coordinate pair as a single 64-bit long integer by shifting x left 32 bits and OR-ing with y. This allows O(1) obstacle lookups.

The robot maintains its current position (x, y) and a direction index (0=north, 1=east, 2=south, 3=west). For rotation commands, it adjusts the direction modulo 4. For movement commands, it advances one unit at a time in the current direction by computing the next position based on the direction index: adding/subtracting 1 to x for east/west and to y for north/south.

Before each step, it checks if the next position contains an obstacle using the hash set. If an obstacle is found, movement stops immediately and the command ends. Otherwise, the robot moves to the new position and updates the maximum squared distance seen so far. After processing all commands, it returns this maximum.

## Complexity

- **Time:** O(n + m)
- **Space:** O(m)

## Stats

- Submitted: 2024-09-04 01:18 UTC
- Runtime: 228 ms
- Memory: 38.8 MB
- Language: C++
