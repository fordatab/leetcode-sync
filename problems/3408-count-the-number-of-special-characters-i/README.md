# Count the Number of Special Characters I

**Difficulty:** Easy
**Tags:** hash-table, string, counting

## Problem

Given a string containing both lowercase and uppercase English letters, count how many distinct letters appear in both their lowercase and uppercase forms. For example, if the string contains both 'a' and 'A', the letter 'a' is considered special. The string length is at most 50 characters.

## Approach

The solution uses a vector of 26 pairs to track the presence of each letter of the alphabet in both cases. Each pair's first element indicates whether the lowercase version has been seen, and the second element tracks the uppercase version.

The algorithm iterates through the input string once. For each character, it determines if it's lowercase or uppercase, then sets the corresponding flag in the appropriate pair (using the character's offset from 'a' or 'A' as the index).

After processing all characters, it counts how many pairs have both flags set to 1, indicating that both the lowercase and uppercase versions of that letter appeared in the string. This count is the final answer.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-06-13 22:34 UTC
- Runtime: 0 ms
- Memory: 9.2 MB
- Language: C++
