# Maximum Palindromes After Operations

**Difficulty:** Medium
**Tags:** greedy, sorting, counting, string, hash-table

## Problem

Given an array of strings, you can swap any character from any position in any string with any character from any position in any other string (or the same string) an unlimited number of times. The goal is to determine the maximum number of strings that can be transformed into palindromes through these swaps. Constraints allow up to 1000 strings, each up to 100 characters long, containing only lowercase English letters.

## Approach

The solution recognizes that unlimited swapping means characters can be redistributed freely across all strings, making the total character pool shared. The key insight is that forming a palindrome of length L requires L/2 pairs of matching characters (the middle character in odd-length palindromes doesn't need a pair).

First, the code counts the frequency of each character across all strings and calculates how many character pairs are available in total (each character appearing N times contributes N/2 pairs). It also stores the length of each string.

Next, it sorts the string lengths in ascending order to greedily satisfy shorter strings first. This greedy approach is optimal because if we can't form a palindrome for a shorter string, we definitely can't form one for a longer string given the same character pool.

Finally, it iterates through the sorted lengths, attempting to form a palindrome for each string by checking if enough pairs remain. For each string of length L, it needs L/2 pairs. If sufficient pairs exist, they're consumed and the palindrome count increments; otherwise, the process stops since longer strings will require even more pairs.

## Complexity

- **Time:** O(n log n + m)
- **Space:** O(n)

## Stats

- Submitted: 2026-07-17 07:09 UTC
- Runtime: 2 ms
- Memory: 28.7 MB
- Language: C++
