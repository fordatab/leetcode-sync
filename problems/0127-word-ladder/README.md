# Word Ladder

**Difficulty:** Hard
**Tags:** breadth-first-search, bidirectional-search, hash-table, string

## Problem

Given a starting word, a target word, and a dictionary of valid words, find the length of the shortest sequence where each step changes exactly one letter and each intermediate word exists in the dictionary. All words have the same length (1-10 characters), the dictionary contains up to 5000 words, and if no valid transformation exists, return 0.

## Approach

This solution uses **bidirectional BFS** to find the shortest path from the start word to the end word. It maintains two sets (`s1` and `s2`) representing the frontier from both directions, starting from `beginWord` and `endWord` respectively.

At each iteration, the algorithm expands the smaller frontier to balance the search. For each word in the current frontier, it generates all possible one-letter mutations by trying each alphabet character at each position. If a mutation exists in the opposite frontier, the two search waves have met, and the answer is the current depth plus one.

Words from the dictionary are removed once visited to prevent revisiting. The bidirectional approach significantly reduces the search space compared to unidirectional BFS, as it grows from both ends simultaneously until they meet in the middle.

## Complexity

- **Time:** O(n * L^2 * 26)
- **Space:** O(n * L)

## Stats

- Submitted: 2024-08-11 01:12 UTC
- Runtime: 19 ms
- Memory: 19.2 MB
- Language: C++
