# Substring with Concatenation of All Words

**Difficulty:** Hard
**Tags:** sliding-window, hash-table, string, two-pointers

## Problem

Given a string and an array of equal-length words, find all starting indices in the string where a substring is formed by concatenating all words in any order (each word used exactly as many times as it appears in the array). The string can be up to 10^4 characters, the words array can contain up to 5000 words, and each word can be up to 30 characters long.

## Approach

The solution uses a sliding window technique optimized by partitioning the search space. Instead of checking every possible starting position in the string, it iterates through only `wordLength` different starting offsets (0 to wordLength-1), and within each offset, moves forward by `wordLength` characters at a time.

For each offset, it maintains a sliding window that tracks seen words using a hash map. As it scans word-by-word chunks:
- If the current word is valid (exists in the target word count), it's added to the window
- If a word's count exceeds what's needed, the window shrinks from the left until the excess is removed
- When the window contains exactly all required words, the starting index is recorded and the window slides forward by one word
- If an invalid word is encountered, the window resets completely

This approach efficiently handles overlapping matches and avoids checking every single character position by leveraging the fixed word length structure.

## Complexity

- **Time:** O(n * m)
- **Space:** O(m)

## Stats

- Submitted: 2024-09-14 02:56 UTC
- Runtime: 18 ms
- Memory: 23.1 MB
- Language: C++
