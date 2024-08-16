# Goal Parser Interpretation

**Difficulty:** Easy
**Tags:** string, parsing, iteration

## Problem

Given a string composed of the tokens "G", "()", and "(al)", translate each token into its corresponding output: "G" stays as "G", "()" becomes "o", and "(al)" becomes "al". The input string length is between 1 and 100 characters, and consists only of these three token types in any combination.

## Approach

The solution iterates through the input string character by character using a single pass. When encountering 'G', it appends 'G' to the output string. When encountering an opening parenthesis '(', it checks the next character: if it's a closing parenthesis ')', it appends 'o' and skips ahead one position; otherwise (when the next character is 'a'), it appends "al" and skips ahead two positions to bypass the "al)" portion. The result string is built incrementally and returned at the end.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-16 01:50 UTC
- Runtime: 0 ms
- Memory: 7.7 MB
- Language: C++
