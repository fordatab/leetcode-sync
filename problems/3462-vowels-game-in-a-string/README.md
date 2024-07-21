# Vowels Game in a String

**Difficulty:** Medium
**Tags:** game-theory, math, string, counting

## Problem

Two players alternate removing substrings from a string, where Alice removes substrings with an odd number of vowels and Bob removes substrings with an even number of vowels. Alice goes first, and both play optimally. The game ends when a player cannot make a valid move, and that player loses. Determine whether Alice wins given the initial string.

## Approach

The solution counts the total number of vowels in the string. If the count is odd, Alice can immediately remove the entire string (which contains an odd number of vowels) and win on her first move. If there are no vowels at all, Alice has no valid moves and loses immediately. Otherwise, when the vowel count is even and positive, Alice can still win: she removes a substring containing exactly one vowel, leaving a string with an odd number of vowels. Now Bob must remove a substring with an even number of vowels from a string with an odd total, which means after his move, an odd number of vowels remain. This pattern continues with Alice always able to maintain odd vowel parity until the string is depleted in her favor.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-21 03:00 UTC
- Runtime: 48 ms
- Memory: 17.5 MB
- Language: C++
