# Check if Numbers Are Ascending in a Sentence

**Difficulty:** Easy
**Tags:** string, parsing, string-stream, simulation

## Problem

Given a sentence string where tokens are separated by single spaces, determine whether all numeric tokens appear in strictly increasing order from left to right. The sentence contains a mix of lowercase words and positive integers (less than 100, no leading zeros), with at least two numbers present. Non-numeric tokens should be ignored when checking the ascending property.

## Approach

The solution uses a string stream to parse the input sentence token by token. It maintains a variable `l` to track the last encountered number (initialized to 0). For each token, it checks if the first character is a digit using `isdigit()`. If the token is numeric, it converts the string to an integer with `stoi()` and compares it against the previous number `l`. If any number is less than or equal to the previous one, the function immediately returns false. Otherwise, it updates `l` to the current number and continues. If all numbers pass the strictly increasing check, the function returns true at the end.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-04 23:12 UTC
- Runtime: 0 ms
- Memory: 8 MB
- Language: C++
