# Shuffle an Array

**Difficulty:** Medium
**Tags:** array, randomization, fisher-yates-shuffle, design

## Problem

Design a data structure that supports shuffling an integer array with equal probability for all permutations. The class must initialize with an array (up to 50 elements with unique values between -10^6 and 10^6), provide a reset method to restore the original array, and a shuffle method to return a random permutation. Up to 10,000 total calls will be made to reset and shuffle.

## Approach

The solution stores the original array in a member variable during construction. The `reset()` method simply returns this stored copy. The `shuffle()` method implements the Fisher-Yates shuffle algorithm: it creates a copy of the original array, then iterates through each position from left to right. At position `i`, it selects a random index from the remaining unshuffled portion (from `i` to the end), then swaps the element at that random position with the element at position `i`. This ensures each permutation has equal probability. The randomness comes from `rand() % (result.size() - i)`, which picks a random offset in the remaining elements, and the swap progressively builds the shuffled array from left to right.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-26 01:54 UTC
- Runtime: 59 ms
- Memory: 62 MB
- Language: C++
