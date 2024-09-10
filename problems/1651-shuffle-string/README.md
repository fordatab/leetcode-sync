# Shuffle String

**Difficulty:** Easy
**Tags:** array, string, simulation

## Problem

Given a string and an array of indices of equal length, rearrange the string so that each character at position i is moved to position indices[i]. The indices array contains unique values from 0 to n-1, where n is the string length (1 ≤ n ≤ 100), and all characters are lowercase English letters.

## Approach

The solution creates a temporary string initialized as a copy of the input string. It then iterates through each position in the original string using a simple for-loop. For each character at position x in the original string, it places that character at position indices[x] in the temporary string. This direct mapping approach reads from the original string sequentially and writes to the correct positions in the result string based on the indices array. After processing all characters, the rearranged string is returned.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-10 06:49 UTC
- Runtime: 4 ms
- Memory: 18.2 MB
- Language: C++
