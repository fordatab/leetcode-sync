# Letter Combinations of a Phone Number

**Difficulty:** Medium
**Tags:** backtracking, recursion, string, depth-first-search

## Problem

Given a string of digits between 2 and 9 (inclusive), generate all possible letter combinations where each digit maps to letters like on a telephone keypad (2→abc, 3→def, etc.). The input string has at most 4 digits, and the output can be in any order.

## Approach

The solution uses recursive depth-first search with backtracking to generate all combinations. It maintains a result string that grows as the recursion explores deeper. For each digit in the input, a switch statement hardcodes the corresponding letters (e.g., digit '2' maps to 'a', 'b', 'c'). For each possible letter, the code:

1. Appends the letter to the current result string
2. Recursively processes the remaining digits via `digits.substr(1)`
3. Backtracks by popping the last character

The base case occurs when the digit string is empty, at which point the accumulated result is added to the output vector. The repeated pattern of push-recurse-pop for each letter ensures all combinations are explored systematically.

## Complexity

- **Time:** O(4^n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-25 22:18 UTC
- Runtime: 2 ms
- Memory: 10 MB
- Language: C++
