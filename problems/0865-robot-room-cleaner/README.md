# Robot Room Cleaner

**Difficulty:** Hard
**Tags:** depth-first-search, backtracking, simulation, graph-traversal

## Problem

Control a robot to clean every accessible cell in an unknown room represented as a grid, where you can only interact through a limited API (move, turnLeft, turnRight, clean). The robot starts at an unknown position facing up, and you must navigate without knowledge of the room layout or starting coordinates. The challenge is to ensure complete coverage of all reachable empty cells using only these blind movement commands.

## Approach

This solution uses depth-first search with backtracking to systematically explore and clean the room. It maintains a set of visited coordinates in a virtual coordinate system (starting at origin 0,0) and tracks the robot's current direction using an index into a direction array (up=0, right=1, down=2, left=3).

At each cell, the algorithm cleans the current position, then tries all four directions in order. For each direction, it rotates the robot appropriately, attempts to move forward, and if successful (cell is open and unvisited), recursively explores that cell. After exploring a branch, it uses a backtrack helper function (`bw`) that turns 180 degrees, moves back to the previous cell, and turns 180 degrees again to restore the original orientation.

The direction tracking is crucial: as the robot turns left at each iteration through the loop, the actual compass direction is computed as `(d + i) % 4`, ensuring the virtual coordinates stay consistent. The visited set prevents revisiting cells and ensures termination when all reachable cells have been cleaned.

## Complexity

- **Time:** O(n - m)
- **Space:** O(n - m)

## Stats

- Submitted: 2026-01-14 22:56 UTC
- Runtime: 3 ms
- Memory: 11.7 MB
- Language: C++
