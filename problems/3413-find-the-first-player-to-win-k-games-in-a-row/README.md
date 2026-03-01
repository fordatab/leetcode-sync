# Find The First Player to win K Games in a Row

**Difficulty:** Medium
**Tags:** queue, simulation, greedy

## Problem

Given an array of unique skill levels representing n players in a queue and an integer k, simulate a competition where the first two players compete, the winner stays at the front, and the loser moves to the back. Return the index of the first player to win k consecutive games. Constraints include n up to 10^5 and k up to 10^9.

## Approach

The solution uses a queue to simulate the competition process. If k is greater than or equal to n, it immediately returns the index of the player with maximum skill since they will eventually win all games. Otherwise, it maintains a `wins` array to track consecutive wins for each player and a queue holding all players except the first. The current front player is stored separately. In each iteration, it compares the current player with the front of the queue: the winner increments their win count (returning if it reaches k), while the loser's count resets to zero and they're sent to the back of the queue. The winner becomes or remains the current player.

## Complexity

- **Time:** O(n * k)
- **Space:** O(n)

## Stats

- Submitted: 2026-03-01 02:49 UTC
- Runtime: 19 ms
- Memory: 139.5 MB
- Language: C++
