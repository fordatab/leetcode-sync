# Count the Number of Special Characters I

**Difficulty:** Easy
**Tags:** string, hash-table, counting

## Problem

Given a string containing uppercase and lowercase English letters, determine how many distinct letters appear in both their lowercase and uppercase forms. For example, if both 'a' and 'A' appear in the string, then 'a' counts as one special character. The string length is between 1 and 50 characters.

## Approach

The solution uses a vector of 26 pairs to track the presence of each letter of the alphabet. Each pair's first element indicates whether the lowercase version of that letter has been seen, and the second element tracks the uppercase version.

The algorithm iterates through the input string once. For each character, it determines if it's lowercase or uppercase, then sets the corresponding flag in the pair for that letter (using the character's offset from 'a' or 'A' as an index).

After processing all characters, the solution counts how many pairs have both flags set to 1, meaning both the lowercase and uppercase versions were encountered. This count is returned as the answer.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-06-13 22:34 UTC
- Runtime: 0 ms
- Memory: 9.2 MB
- Language: C++
