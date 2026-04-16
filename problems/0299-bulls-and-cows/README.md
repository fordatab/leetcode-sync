# Bulls and Cows

**Difficulty:** Medium
**Tags:** hash-table, string, counting

## Problem

Given two equal-length digit strings representing a secret number and a guess, determine how many digits match exactly at the same position (bulls) and how many digits exist in both strings but at different positions (cows). Return the result formatted as "xAyB" where x is the bull count and y is the cow count. Each digit in the guess can only be matched once, prioritizing exact position matches.

## Approach

The solution uses two hash maps to count character frequencies. First, it builds a frequency map of all digits in the secret string. Then it makes a single pass through both strings simultaneously: when digits match at the same index, it increments the bull counter and decrements that digit's count in the secret map; when they don't match, it stores the mismatched guess digit in a second map. Finally, it iterates through the mismatched guess digits and counts cows by taking the minimum between each digit's frequency in the guess and its remaining frequency in the secret map (which already has bulls subtracted). This ensures each digit is only counted once and bulls take precedence over cows.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-04-16 09:42 UTC
- Runtime: 4 ms
- Memory: 9.2 MB
- Language: C++
