# Reverse Vowels of a String

**Difficulty:** Easy
**Tags:** two-pointers, string, in-place

## Problem

Given a string containing printable ASCII characters with length up to 300,000, reverse the positions of all vowels (a, e, i, o, u, both uppercase and lowercase) while keeping consonants in their original positions. The modified string should be returned.

## Approach

The solution uses a two-pointer technique to swap vowels in-place. A helper function `isvowel` checks whether a character is a vowel by converting it to lowercase and comparing against the five vowel characters.

Two pointers start at opposite ends of the string: `l` at the beginning and `r` at the end. The algorithm advances `l` forward until it finds a vowel, and moves `r` backward until it finds a vowel. When both pointers point to vowels and haven't crossed each other, the characters are swapped using a temporary variable.

After each swap, both pointers move inward (`l++` and `r--`), and the process repeats until the pointers meet or cross. The modified string is then returned. The debug output statements (`cout`) print the string size and each pair of vowels being swapped, though these don't affect the correctness of the solution.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-13 05:53 UTC
- Runtime: 16 ms
- Memory: 9.3 MB
- Language: C++
