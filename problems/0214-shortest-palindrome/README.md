# Shortest Palindrome

**Difficulty:** Hard
**Tags:** string, palindrome, string-matching, greedy

## Problem

Given a string, find the shortest palindrome that can be formed by adding characters only to the front of it. The task is to minimize the number of characters prepended while ensuring the result reads the same forwards and backwards. The input string can be up to 50,000 characters long and contains only lowercase English letters.

## Approach

The solution finds the longest prefix of the original string that is also a palindrome, then prepends the necessary suffix characters in reverse.

First, it creates a reversed copy of the input string. Then it iterates through possible split points, checking if the original string matches the tail portion of the reversed string using `memcmp` for efficient comparison without creating substrings.

When a match is found at position `i`, it means the first `s.size() - i` characters of the original string form a palindrome. The solution then prepends the first `i` characters of the reversed string (which are the last `i` characters of the original in reverse order) to complete the palindrome.

The `memcmp` comparison at each position checks whether `s[0..n-i-1]` equals `reversed[i..n-1]`, effectively testing if the prefix is palindromic. This avoids the overhead of substring creation while finding the longest palindromic prefix.

## Complexity

- **Time:** O(n^2)
- **Space:** O(n)

## Stats

- Submitted: 2026-01-30 21:15 UTC
- Runtime: 19 ms
- Memory: 12.4 MB
- Language: C++
