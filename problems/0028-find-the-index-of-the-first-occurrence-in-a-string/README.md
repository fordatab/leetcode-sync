# Find the Index of the First Occurrence in a String

**Difficulty:** Easy
**Tags:** string, two-pointers, brute-force, substring-matching

## Problem

Find the starting position of a substring (needle) within a larger string (haystack), returning the index of its first occurrence or -1 if not found. Both strings contain only lowercase English letters and can be up to 10,000 characters long.

## Approach

The solution uses a brute-force substring matching approach. It iterates through each valid starting position in the haystack (from index 0 to m-n, where m is the haystack length and n is the needle length). At each position i, it attempts to match the needle character-by-character using an inner loop that compares haystack[i+j] with needle[j]. If all characters match (indicated by j reaching n), the current index i is returned as the first occurrence. If no match is found after checking all positions, -1 is returned.

## Complexity

- **Time:** O(m * n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-28 05:09 UTC
- Runtime: 3 ms
- Memory: 7.9 MB
- Language: C++
