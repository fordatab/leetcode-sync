# Truncate Sentence

**Difficulty:** Easy
**Tags:** string, iteration, counting

## Problem

Given a sentence string where words are separated by single spaces and an integer k, return a truncated version of the sentence containing only the first k words. The input is guaranteed to have at least k words, no leading or trailing spaces, and words consist only of English letters.

## Approach

The solution iterates through the sentence character by character, counting spaces encountered. Since words are separated by single spaces, the number of spaces indicates how many words have been completed. When the space count reaches k, it means we've just finished the k-th word, so we return a substring from the beginning up to (but not including) that space position. If we traverse the entire string without finding k spaces, it means the sentence has exactly k words, so we return the original string unchanged.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-21 07:20 UTC
- Runtime: 0 ms
- Memory: 7.9 MB
- Language: C++
