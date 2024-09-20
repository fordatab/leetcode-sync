# Check if a String Is an Acronym of Words

**Difficulty:** Easy
**Tags:** array, string, simulation

## Problem

Given an array of strings and a target string, determine whether the target string can be formed by taking the first character of each word in the array in order. The lengths must match, and each first character must align with the corresponding position in the target string.

## Approach

The solution first checks if the number of words matches the length of the target string `s`. If the lengths differ, it immediately returns false since a valid acronym requires exactly one character per word. Then it iterates through the minimum of the two lengths (though this is redundant after the length check), comparing the first character of each word with the corresponding character in `s`. If any mismatch is found, it returns false. If all characters match, it returns true.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-20 06:14 UTC
- Runtime: 11 ms
- Memory: 43.3 MB
- Language: C++
