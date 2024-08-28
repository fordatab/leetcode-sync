# Minimum Number Game

**Difficulty:** Easy
**Tags:** sorting, array, simulation, greedy

## Problem

Given an even-length array of integers, simulate a game where Alice and Bob alternately remove the two smallest elements from the array in each round. In each round, Alice removes the minimum first, Bob removes the next minimum, then Bob appends his element to the result array followed by Alice appending hers. Return the final result array after all rounds are complete.

## Approach

The solution sorts the input array in ascending order, then iterates through it in pairs. For each consecutive pair of elements (representing what Alice and Bob remove in a single round), the code swaps their positions in the output array—placing the second element (Bob's) before the first (Alice's). This directly simulates the append order without needing to track removals or intermediate states. By processing sorted pairs and reversing each pair's order, the solution efficiently constructs the required result.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-28 04:56 UTC
- Runtime: 7 ms
- Memory: 27.5 MB
- Language: C++
