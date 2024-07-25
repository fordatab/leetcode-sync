# Hand of Straights

**Difficulty:** Medium
**Tags:** greedy, hash-table, ordered-map, sorting

## Problem

Given an array of card values and a target group size, determine whether all cards can be partitioned into groups where each group contains exactly groupSize cards with consecutive values. The array length can be up to 10,000, card values range from 0 to 10^9, and groupSize is between 1 and the array length.

## Approach

The solution uses a frequency map (std::map) to count occurrences of each card value, which automatically keeps keys sorted. It repeatedly attempts to form groups by:

1. Taking the smallest remaining card value as the starting point of a new group
2. Attempting to form a consecutive sequence of groupSize cards starting from this value
3. For each required card in the sequence, checking if it exists in the map and decrementing its count
4. Removing cards from the map when their count reaches zero
5. If any required card is missing during group formation, returning false

The key insight is that by always starting with the minimum available card value, we greedily form groups in a way that maximizes our chances of success — if a valid partitioning exists, this greedy approach will find it.

## Complexity

- **Time:** O(n * groupSize * log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-25 00:50 UTC
- Runtime: 53 ms
- Memory: 32 MB
- Language: C++
