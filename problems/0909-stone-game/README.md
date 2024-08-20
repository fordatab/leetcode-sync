# Stone Game

**Difficulty:** Medium
**Tags:** math, game-theory, greedy

## Problem

Two players alternate picking piles of stones from either end of a row containing an even number of piles. The total number of stones is odd, guaranteeing no tie. Alice moves first, and both players play optimally to maximize their own stone count. The task is to determine whether Alice wins.

## Approach

This solution exploits a mathematical property of the game setup. Since there are an even number of piles, Alice can always guarantee a win by choosing a strategy to control either all even-indexed or all odd-indexed piles. On her first move, Alice can choose to take from the left (accessing even indices going forward) or right (accessing odd indices going backward). Because the total is odd and she gets first pick of which parity group to control, Alice can always secure more stones than Bob regardless of the pile values. The code simply returns `true` without any computation, recognizing that Alice wins in every valid game configuration.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-20 02:04 UTC
- Runtime: 4 ms
- Memory: 9.5 MB
- Language: C++
