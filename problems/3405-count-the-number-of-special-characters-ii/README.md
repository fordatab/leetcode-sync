# Count the Number of Special Characters II

**Difficulty:** Medium
**Tags:** string, array, simulation, state-tracking

## Problem

Given a string containing uppercase and lowercase English letters, count how many letters qualify as "special." A letter is special if both its lowercase and uppercase forms appear in the string, and crucially, all lowercase occurrences must come strictly before the first uppercase occurrence of that letter. The string can be up to 200,000 characters long.

## Approach

The solution uses a vector of 26 pairs to track the state of each letter (a-z). Each pair stores two flags: the first indicates whether lowercase occurrences are valid (1 if all lowercase appear before any uppercase, -1 if a lowercase appears after uppercase), and the second indicates whether the uppercase form exists.

The algorithm scans the string once. For lowercase letters, it checks if the corresponding uppercase has already been seen (second flag > 0). If so, it marks the letter as invalid by setting the first flag to -1. Otherwise, it marks that a valid lowercase occurrence exists (first flag = 1). For uppercase letters, it simply sets the second flag to 1.

After processing the entire string, it counts how many letters have first flag equal to 1 (valid lowercase positioning) and second flag set (uppercase exists), which are the special characters.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-06-13 23:53 UTC
- Runtime: 61 ms
- Memory: 24.2 MB
- Language: C++
