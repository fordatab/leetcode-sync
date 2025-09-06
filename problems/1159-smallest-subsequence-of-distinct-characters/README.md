# Smallest Subsequence of Distinct Characters

**Difficulty:** Medium
**Tags:** stack, greedy, string, monotonic-stack

## Problem

Given a string of lowercase English letters with length up to 1000, find the lexicographically smallest subsequence that includes each distinct character from the original string exactly once. The result must preserve the relative ordering of characters from the input string (as it's a subsequence, not a rearrangement).

## Approach

The solution uses a greedy stack-based approach with character frequency tracking. It maintains a count array to track remaining occurrences of each character and a boolean array to mark which characters are already in the result stack.

As we iterate through the string, we decrement the count for each character. If a character is already in our stack, we skip it. Otherwise, we greedily pop characters from the stack that are lexicographically larger than the current character, but only if they appear again later in the string (count > 0). This ensures we can still include them while achieving a smaller lexicographic order.

After popping qualifying characters, we push the current character onto the stack and mark it as included. Finally, we build the result string by popping all characters from the stack in reverse order (since stack is LIFO).

The key insight is that we can safely remove a larger character from our current result if it appears later, allowing us to place a smaller character first and achieve better lexicographic ordering.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2025-09-06 10:59 UTC
- Runtime: 0 ms
- Memory: 8.8 MB
- Language: C++
