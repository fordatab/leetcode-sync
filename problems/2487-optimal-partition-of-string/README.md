# Optimal Partition of String

**Difficulty:** Medium
**Tags:** greedy, hash-set, string, partition

## Problem

Given a string of lowercase English letters (length up to 10^5), split it into the minimum number of substrings where each substring contains only unique characters — no character appears more than once within any single substring. Every character must belong to exactly one substring in the partition.

## Approach

The solution uses a greedy approach with a hash set to track characters in the current substring. It iterates through the string character by character, attempting to insert each character into the set. If insertion fails (meaning the character already exists in the current substring), the algorithm increments the partition counter, clears the set to start a new substring, and adds the current character to the fresh set. After processing all characters, it returns the counter plus one to account for the final substring that was being built.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-03-03 05:19 UTC
- Runtime: 145 ms
- Memory: 47.3 MB
- Language: C++
