# Count Binary Substrings

**Difficulty:** Easy
**Tags:** string, two-pointers, sliding-window

## Problem

Given a binary string, count all non-empty substrings where zeros and ones appear in equal quantities and each digit type forms a single consecutive group. For instance, "0011" is valid (two consecutive 0s followed by two consecutive 1s), but "0101" is not (digits aren't grouped). The string can be up to 100,000 characters long.

## Approach

The solution scans through the string looking for boundaries where the character changes (from '0' to '1' or vice versa). At each boundary position `m`, it attempts to expand outward symmetrically: checking positions `m-1-l` and `m+l` to see if they continue the pattern of consecutive identical characters on each side. For each valid expansion step where `s[m-1-l]` matches `s[m-1]` and `s[m+l]` matches `s[m]`, it increments both the counter `out` and the expansion distance `l`. The algorithm moves forward one position at a time through the string, accumulating all valid substrings centered at character boundaries.

## Complexity

- **Time:** O(n^2)
- **Space:** O(1)

## Stats

- Submitted: 2026-03-04 11:05 UTC
- Runtime: 1185 ms
- Memory: 13.2 MB
- Language: C++
