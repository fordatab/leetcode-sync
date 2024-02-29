# Check if the Sentence Is Pangram

**Difficulty:** Easy
**Tags:** bit-manipulation, string, hash-table

## Problem

Given a string containing only lowercase English letters, determine whether it contains all 26 letters of the alphabet at least once. The string length ranges from 1 to 1000 characters.

## Approach

The solution uses a bitmask to track which letters have been encountered. It initializes a 32-bit integer `a` to zero, where each of the lower 26 bits represents one letter of the alphabet. As it iterates through each character in the sentence, it computes the character's offset from 'a' (0-25) and creates a bitmask `b` by left-shifting 1 by that offset. This bitmask is then OR-ed with the accumulator `a`, setting the corresponding bit for that letter. After processing all characters, it checks if `a` equals `0x03ffffff` (binary: 26 ones in the lower bits), which indicates all 26 letters have been seen. The debug `printf` statements suggest this was developed incrementally but don't affect correctness.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-02-29 23:57 UTC
- Runtime: 24 ms
- Memory: 5.3 MB
- Language: C
