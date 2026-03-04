# Count Vowel Strings in Ranges

**Difficulty:** Medium
**Tags:** prefix-sum, array, string

## Problem

Given an array of strings and multiple range queries, count how many strings in each specified range (inclusive) both start and end with a vowel (a, e, i, o, u). The array can contain up to 100,000 strings with a total character count up to 300,000, and there can be up to 100,000 queries.

## Approach

The solution uses a prefix sum array to efficiently answer multiple range queries. First, it builds a helper function `isVowel` to check if a character is a vowel. Then it constructs a prefix sum array where `prefix[i]` stores the count of valid strings (those starting and ending with vowels) from index 0 to i-1 in the original words array. For each word at index i-1, it checks both the first character and the last character; if both are vowels, it increments the count.

To answer each query `[l, r]`, it performs a range sum calculation using the prefix array: `prefix[r+1] - prefix[l]` gives the count of valid strings in the range. This avoids repeatedly scanning the range for each query. The prefix array has size n+1 (where n is the number of words) with `prefix[0] = 0` as the base case, allowing clean range calculations.

## Complexity

- **Time:** O(n + q)
- **Space:** O(n)

## Stats

- Submitted: 2026-03-04 10:34 UTC
- Runtime: 20 ms
- Memory: 74.5 MB
- Language: C++
