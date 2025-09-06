# Remove Duplicate Letters

**Difficulty:** Medium
**Tags:** stack, greedy, string, monotonic-stack

## Problem

Given a string of lowercase letters, construct a subsequence containing each distinct character exactly once, ensuring the result is the lexicographically smallest possible among all valid subsequences. The input string has length up to 10,000 and contains only lowercase English letters.

## Approach

The solution uses a greedy stack-based approach with character frequency tracking. It maintains a count array to track remaining occurrences of each character and a boolean array to track which characters are already in the result stack.

As we iterate through the string, we decrement the count for the current character. If the character is already in our stack, we skip it. Otherwise, we greedily remove characters from the top of the stack if they are lexicographically larger than the current character AND still appear later in the string (count > 0). This ensures we can safely postpone including them.

After these removals, we push the current character onto the stack and mark it as included. Finally, we build the result string by popping characters from the stack in reverse order, since the stack gives us the characters in the order they should appear.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2025-09-06 10:49 UTC
- Runtime: 0 ms
- Memory: 9.7 MB
- Language: C++
