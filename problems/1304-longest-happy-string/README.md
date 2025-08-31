# Longest Happy String

**Difficulty:** Medium
**Tags:** greedy, string, heap

## Problem

Given three non-negative integers representing maximum allowed counts of characters 'a', 'b', and 'c', construct the longest possible string using only these three characters such that no character appears three or more times consecutively. The string must use at most the specified count of each character.

## Approach

The solution uses a greedy approach that repeatedly selects characters based on their remaining counts. It maintains a vector of (count, character) pairs and iterates while any character remains available.

In each iteration, it identifies the character with the maximum remaining count and the second-maximum. It adds 1-2 instances of the most frequent character to the output string, deciding between 1 or 2 based on whether the count significantly exceeds the second-most frequent character (using a threshold of +2). Then it adds 1-2 instances of the second-most frequent character, again choosing the count based on comparing remaining values.

The algorithm terminates when no second character is available to alternate with, preventing three consecutive identical characters. It updates the counts in the vector after each addition and synchronizes the individual a, b, c variables for the loop condition.

## Complexity

- **Time:** O(a + b + c)
- **Space:** O(a + b + c)

## Stats

- Submitted: 2025-08-31 06:09 UTC
- Runtime: 0 ms
- Memory: 8.2 MB
- Language: C++
