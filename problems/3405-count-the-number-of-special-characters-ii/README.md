# Count the Number of Special Characters II

**Difficulty:** Medium
**Tags:** string, hash-table, array, two-pointer

## Problem

Given a string containing both uppercase and lowercase English letters, count how many letters qualify as "special". A letter is special if it appears in both cases and all lowercase occurrences come strictly before any uppercase occurrence. The string can be up to 200,000 characters long.

## Approach

The solution uses a vector of 26 pairs to track the state of each letter (a-z). Each pair stores two flags: the first indicates the lowercase status (1 if only lowercase seen, -1 if lowercase appeared after uppercase), and the second indicates if the uppercase version has been encountered.

The algorithm makes a single pass through the string. For each lowercase character, it checks if the corresponding uppercase has already been seen. If so, it marks the first element as -1 (disqualified). Otherwise, it marks it as 1 (valid lowercase encountered). For each uppercase character, it simply sets the second element to 1.

After processing all characters, it counts pairs where the first element is exactly 1 (meaning lowercase appeared but never after uppercase) and the second element is non-zero (uppercase exists). This count represents letters that satisfy both the case-presence and ordering requirements.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-06-13 23:53 UTC
- Runtime: 61 ms
- Memory: 24.2 MB
- Language: C++
