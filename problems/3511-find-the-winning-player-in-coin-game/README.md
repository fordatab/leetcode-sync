# Find the Winning Player in Coin Game

**Difficulty:** Easy
**Tags:** math, game-theory, greedy

## Problem

Given x coins worth 75 and y coins worth 10, Alice and Bob alternate turns (Alice first) where each player must collect exactly 115 in coin value per turn. A player loses if they cannot collect 115. The task is to determine the winner assuming both play optimally. Constraints limit x and y to values between 1 and 100.

## Approach

The solution recognizes that collecting exactly 115 requires one 75-coin and four 10-coins (75 + 4×10 = 115). The key insight is that the game continues for as many turns as both coin types can support such combinations. The limiting factor is whichever runs out first: either the 75-coins (x) or groups of four 10-coins (y/4). The code calculates `min(x, y/4)` to find the total number of valid turns possible. Since Alice goes first, if the number of turns is odd, Alice makes the last valid move and wins; if even, Bob makes the last move and wins. The result is determined by checking if turns is odd (Alice wins) or even (Bob wins).

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-21 00:49 UTC
- Runtime: 4 ms
- Memory: 7.6 MB
- Language: C++
