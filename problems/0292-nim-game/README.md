# Nim Game

**Difficulty:** Easy
**Tags:** math, game-theory, brainteaser

## Problem

In a two-player game starting with n stones, players alternate turns removing 1-3 stones, with the player who takes the last stone winning. The first player moves first, and both play optimally. Determine whether the first player can guarantee a win given the initial stone count n, where n can be as large as 2^31 - 1.

## Approach

The solution exploits a mathematical pattern in optimal Nim game play. When the stone count is divisible by 4, the first player is in a losing position because whatever move they make (removing 1, 2, or 3 stones), the second player can respond by removing enough stones to make the total removed equal to 4, maintaining the invariant. Conversely, if the initial count is not divisible by 4, the first player can always remove enough stones to leave a multiple of 4 for the opponent, forcing them into a losing position. The code simply checks if n modulo 4 is non-zero: if true, the first player wins; otherwise, they lose.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-25 02:06 UTC
- Runtime: 2 ms
- Memory: 7.1 MB
- Language: C++
