# Find First Palindromic String in the Array

**Difficulty:** Easy
**Tags:** two-pointers, string, array

## Problem

Given an array of strings, find and return the first string that reads the same forwards and backwards. If no such palindromic string exists in the array, return an empty string. The input array contains between 1 and 100 strings, each consisting of 1 to 100 lowercase English letters.

## Approach

The solution uses a straightforward linear search approach with a helper function for palindrome checking.

The `is_pali` helper function checks if a single string is palindromic by using two pointers: one starting at the beginning (`l`) and one at the end (`r`) of the string. It iteratively compares characters at these positions while moving the pointers toward the center. If any pair of characters doesn't match, the function immediately returns false; otherwise, it returns true after all comparisons succeed.

The main `firstPalindrome` function iterates through the input array in order, calling `is_pali` on each string. As soon as a palindromic string is found, it's immediately returned. If the loop completes without finding any palindrome, an empty string is returned.

## Complexity

- **Time:** O(n * m)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-19 06:10 UTC
- Runtime: 51 ms
- Memory: 23.6 MB
- Language: C++
