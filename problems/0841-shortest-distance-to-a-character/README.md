# Shortest Distance to a Character

**Difficulty:** Easy
**Tags:** array, two-pointer, string, greedy

## Problem

Given a string and a target character that appears at least once in it, compute for each position the minimum distance to any occurrence of that character. The distance is measured as the absolute difference between indices. The result is an array where each element represents the shortest distance from that index to the nearest target character.

## Approach

The solution uses a two-pass strategy to find the minimum distance from each position to the nearest target character.

First, it initializes an output array with INT_MAX and marks all positions where the target character appears with distance 0.

In the second pass (left-to-right), it tracks the most recent occurrence of the target character and updates each position with its distance to this nearest occurrence on the left.

In the third pass (right-to-left), it similarly tracks the nearest occurrence to the right and updates each position by taking the minimum of its current value and the distance to the nearest occurrence on the right.

This ensures each position holds the minimum distance to either the nearest left or right occurrence of the target character.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-17 04:28 UTC
- Runtime: 0 ms
- Memory: 8.2 MB
- Language: C++
