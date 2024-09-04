# First Letter to Appear Twice

**Difficulty:** Easy
**Tags:** array, hash-table, string, counting

## Problem

Given a string of lowercase English letters, find the first character that appears twice in the string. A character 'appears twice' when its second occurrence comes before the second occurrence of any other repeated character. The string is guaranteed to contain at least one repeated letter, has a length between 2 and 100, and consists only of lowercase English letters.

## Approach

The solution uses a frequency array to track character occurrences. It maintains a vector of 26 integers (one for each lowercase letter) initialized to zero. As we iterate through the string, for each character, we check its current count in the array. The key insight is using the post-increment operator: `a[c-'a']++` returns the value *before* incrementing. So when we encounter a character for the first time, it returns 0; when we encounter it for the second time, it returns 1. The moment we see a count of 1 (meaning this is the second occurrence), we immediately return that character. The character offset `c-'a'` maps each letter to an index from 0 to 25.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-04 23:20 UTC
- Runtime: 3 ms
- Memory: 7.6 MB
- Language: C++
