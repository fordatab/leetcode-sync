# Minimum Number of Moves to Make Palindrome

**Difficulty:** Hard
**Tags:** greedy, two-pointers, string, palindrome

## Problem

Given a string of lowercase letters, find the minimum number of adjacent-character swaps needed to rearrange it into a palindrome. The string is guaranteed to have a valid palindrome arrangement. The string length can be up to 2000 characters.

## Approach

The solution uses a greedy two-pointer approach, working from the outside in. It processes the string by repeatedly matching the last character with its corresponding position from the left side. For each iteration:

- Find the leftmost occurrence of the current last character using `find()`
- If this position is already at the end (meaning it's the middle character in an odd-length string), add half its index to the move count (representing the cost to move it to the center)
- Otherwise, add the index to the move count (the number of swaps needed to move this character to its paired position), then remove this character from the string
- Remove the last character and repeat

The key insight is that by greedily pairing characters from the outside in, we can count the exact number of swaps: each character needs to be moved from its current position to where its pair should be, and the number of swaps equals the distance it travels.

## Complexity

- **Time:** O(n²)
- **Space:** O(1)

## Stats

- Submitted: 2026-03-03 04:49 UTC
- Runtime: 0 ms
- Memory: 9.5 MB
- Language: C++
