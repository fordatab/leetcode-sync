# Length of Last Word

**Difficulty:** Easy
**Tags:** string, two-pointers, reverse-traversal

## Problem

Given a string containing words separated by spaces, determine the length of the final word in the string. A word is defined as a contiguous sequence of non-space characters. The string may contain leading or trailing spaces and is guaranteed to have at least one word, with a maximum length of 10,000 characters.

## Approach

The solution traverses the string from right to left using a single pass. It maintains a boolean flag `space` to track whether we're currently in a trailing space region or have found the last word. When the first non-space character is encountered from the right, we mark its position in variable `r` and set `space` to false. We continue iterating leftward until we hit a space character while `space` is false, which marks the beginning of the last word. At that point, we calculate and return the word length as `r - x`. If we reach the start of the string without finding a space (meaning the entire string or its non-trailing portion is one word), we return `r + 1` to account for zero-based indexing.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-28 05:19 UTC
- Runtime: 0 ms
- Memory: 8.1 MB
- Language: C++
