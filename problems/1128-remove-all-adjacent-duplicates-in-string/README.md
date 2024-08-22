# Remove All Adjacent Duplicates In String

**Difficulty:** Easy
**Tags:** stack, string, simulation

## Problem

Given a string of lowercase English letters, repeatedly remove pairs of adjacent identical characters until no more removals are possible. The string can be up to 10^5 characters long. Return the final string after all possible removals have been completed.

## Approach

This solution uses a string as a stack to efficiently process the input. It iterates through each character in the input string once. For each character, it checks if the result string is non-empty and whether the last character in the result matches the current character. If they match, it removes the last character from the result (simulating the duplicate removal); otherwise, it appends the current character to the result. This approach naturally handles cascading removals because newly adjacent characters are automatically checked in subsequent iterations.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-22 07:33 UTC
- Runtime: 13 ms
- Memory: 12.3 MB
- Language: C++
