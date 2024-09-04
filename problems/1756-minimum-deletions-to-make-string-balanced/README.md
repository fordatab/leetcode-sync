# Minimum Deletions to Make String Balanced

**Difficulty:** Medium
**Tags:** string, prefix-sum, greedy, dynamic-programming

## Problem

Given a string containing only 'a' and 'b' characters, determine the minimum number of deletions needed to make it balanced. A string is balanced if no 'b' appears before any 'a' (equivalently, all 'a's come before all 'b's). The string length can be up to 100,000 characters.

## Approach

The solution uses prefix and suffix counting to find the optimal split point. It builds two auxiliary arrays: `b[i]` stores the count of 'b' characters before position `i`, and `a[i]` stores the count of 'a' characters after position `i`. For each position `i` in the string, the total deletions needed if we make a split at that position equals `b[i] + a[i]` — we delete all 'b's before position `i` and all 'a's after position `i`, ensuring everything to the left is 'a' and everything to the right is 'b'. The algorithm iterates through all possible split points and returns the minimum sum found. This approach works because a balanced string must have all 'a's before all 'b's, so we're essentially finding where to place the boundary between the 'a' section and 'b' section.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-04 22:56 UTC
- Runtime: 72 ms
- Memory: 53.2 MB
- Language: C++
