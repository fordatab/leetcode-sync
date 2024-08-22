# Longest Palindrome

**Difficulty:** Easy
**Tags:** hash-table, string, greedy, counting

## Problem

Given a string containing uppercase and lowercase English letters, determine the maximum length of a palindrome that can be constructed by rearranging those letters. Letters are case-sensitive, meaning 'A' and 'a' are distinct characters. The string length is constrained between 1 and 2000 characters.

## Approach

The solution uses a frequency-counting approach with a character array. First, it counts the occurrence of each character using a 128-element vector (covering all ASCII characters). Then it iterates through all counts, adding each count to the running length. For characters with odd counts, it subtracts 1 (to make them even) and sets a flag indicating at least one odd count exists. The key insight is that a palindrome can use all even-count characters fully, plus all but one character from each odd-count group, with exactly one odd character placed in the center. The final length calculation adds back 1 if any odd count was found, accounting for that center character.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-22 09:51 UTC
- Runtime: 0 ms
- Memory: 8.2 MB
- Language: C++
