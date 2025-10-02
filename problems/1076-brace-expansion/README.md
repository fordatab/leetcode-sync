# Brace Expansion

**Difficulty:** Medium
**Tags:** backtracking, string, recursion, combinatorics

## Problem

Given a string with optional character choices enclosed in curly braces (e.g., "{a,b}c" means first character can be 'a' or 'b', second must be 'c'), generate all possible word combinations. Characters outside braces are fixed, while those inside braces represent alternatives separated by commas. Return all valid combinations in lexicographical order. The input string length is at most 50, contains no nested braces, and all characters within a brace group are distinct.

## Approach

The solution uses backtracking to generate all possible combinations. Starting from index 0, it recursively processes each position in the input string:

- When encountering a regular character, it appends it to the current string and recursively processes the next position.
- When encountering an opening brace '{', it extracts all comma-separated options until the closing brace '}', sorts these choices alphabetically (ensuring lexicographical output), then recursively tries each option by appending it to the current string.
- The base case occurs when the index reaches the end of the input string, at which point the completed combination is added to the result vector.

The backtracking nature is evident in the push/pop pattern: after exploring each branch with a particular character choice, it removes that character (pop_back) before trying the next option. This ensures each path is explored independently while maintaining the correct partial string state.

## Complexity

- **Time:** O(n * k^m)
- **Space:** O(n * k^m)

## Stats

- Submitted: 2025-10-02 02:16 UTC
- Runtime: 7 ms
- Memory: 13.7 MB
- Language: C++
