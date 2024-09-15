# Snakes and Ladders

**Difficulty:** Medium
**Tags:** breadth-first-search, graph, matrix, shortest-path

## Problem

Given an n×n board with cells labeled 1 to n² in a boustrophedon (alternating zigzag) pattern starting from the bottom-left, find the minimum number of dice rolls (1-6 steps per roll) needed to reach the final cell. Some cells contain snakes or ladders that force you to jump to a different cell. Return -1 if reaching the end is impossible.

## Approach

The solution uses BFS to find the shortest path from cell 1 to cell n².

First, it preprocesses the board by creating a mapping from each cell label (1 to n²) to its (row, column) coordinates, accounting for the boustrophedon pattern. It builds this by traversing rows from bottom to top, alternating the column direction for each row.

Then it performs BFS starting from cell 1. For each cell, it explores all possible moves (rolling 1-6 on the die). For each potential next position, it checks if that cell has a snake or ladder; if so, the actual destination is the value stored at that cell's coordinates, otherwise the destination is the next position itself.

The BFS tracks the minimum number of moves to reach each cell using a distance array. Once a cell is visited, it's never revisited, ensuring we find the shortest path. The algorithm returns the distance to cell n², or -1 if it was never reached.

## Complexity

- **Time:** O(n²)
- **Space:** O(n²)

## Stats

- Submitted: 2024-09-15 05:22 UTC
- Runtime: 11 ms
- Memory: 16.6 MB
- Language: C++
