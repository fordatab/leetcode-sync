# Find Resultant Array After Removing Anagrams

**Difficulty:** Easy
**Tags:** array, string, hash-table, greedy

## Problem

Given an array of lowercase strings, repeatedly remove any string that is an anagram of its immediate predecessor until no more removals are possible. The array can have up to 100 strings, each up to 10 characters long. Two strings are anagrams if they contain the same characters with the same frequencies.

## Approach

The solution makes a single pass through the input array, comparing each word with its predecessor to check if they are anagrams. It maintains a result vector initialized with the first word. For each subsequent word, it uses a helper lambda function that checks if two words are anagrams by counting character frequencies: it increments a frequency array for characters in the first word and decrements for characters in the second word, then verifies all counts are zero using `all_of`. If the current word is not an anagram of the previous word in the original array, it's added to the result. This effectively removes consecutive anagrams in a single forward scan, which works because removing a word at position i makes the word at position i+1 become adjacent to the word at position i-1, and the linear scan naturally handles this cascading effect.

## Complexity

- **Time:** O(n * m)
- **Space:** O(n)

## Stats

- Submitted: 2026-03-05 01:11 UTC
- Runtime: 0 ms
- Memory: 17.9 MB
- Language: C++
