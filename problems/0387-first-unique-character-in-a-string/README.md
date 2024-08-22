# First Unique Character in a String

**Difficulty:** Easy
**Tags:** hash-table, string, counting, frequency-array

## Problem

Given a string containing only lowercase English letters, identify the index of the first character that appears exactly once in the string. If no such character exists, return -1. The string length can be up to 100,000 characters.

## Approach

The solution uses a frequency counting approach with two passes through the string. First, it creates a fixed-size array of 26 integers (one for each lowercase letter) and counts the occurrences of each character by mapping characters to array indices using the offset from 'a'. In the second pass, it iterates through the original string in order and checks the frequency array for each character. The first character with a count of exactly 1 is returned as the answer. If no unique character is found after scanning the entire string, -1 is returned.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-22 09:06 UTC
- Runtime: 20 ms
- Memory: 13.1 MB
- Language: C++
