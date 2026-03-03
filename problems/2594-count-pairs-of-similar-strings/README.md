# Count Pairs Of Similar Strings

**Difficulty:** Easy
**Tags:** bit-manipulation, hash-table, string, counting

## Problem

Given an array of strings, count how many pairs of strings share the exact same set of distinct characters, regardless of frequency or order. Two strings are considered similar if they contain the same alphabet letters (for example, "aba" and "aabb" are similar because both contain only 'a' and 'b'). Return the total number of valid pairs (i, j) where i < j.

## Approach

The solution uses bit manipulation to represent each word's character set as a compact integer signature. For each word, it builds a bitmask by setting bit positions corresponding to each character ('a' maps to bit 0, 'b' to bit 1, etc.). This bitmask uniquely identifies the set of characters present in the word.

A hash map tracks how many words with each bitmask signature have been seen so far. When processing a word with bitmask `bits`, the current count `m[bits]` represents how many previous words share the same character set, which equals the number of new pairs this word forms. After adding these pairs to the result, the count for this bitmask is incremented.

This approach efficiently groups words by their character sets without needing to compare every pair directly, leveraging the fact that two words are similar if and only if their bitmasks are identical.

## Complexity

- **Time:** O(n * k)
- **Space:** O(n)

## Stats

- Submitted: 2026-03-03 22:19 UTC
- Runtime: 0 ms
- Memory: 16.3 MB
- Language: C++
