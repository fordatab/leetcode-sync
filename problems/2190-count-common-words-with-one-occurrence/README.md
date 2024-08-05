# Count Common Words With One Occurrence

**Difficulty:** Easy
**Tags:** hash-table, string, counting

## Problem

Given two arrays of strings, count how many strings appear exactly once in the first array and exactly once in the second array. A string must satisfy both conditions simultaneously to be counted. The arrays can contain up to 1000 strings each, with individual strings up to 30 characters long.

## Approach

The solution uses two hash maps to track the frequency of each string in both input arrays. First, it iterates through `words1` to build a frequency map `m`, then iterates through `words2` to build a second frequency map `m1`. Finally, it iterates through `words1` again, checking each string: if it appears exactly once in both maps (frequency equals 1 in both `m` and `m1`), it increments the counter. The key insight is that by counting frequencies separately and then checking both conditions, we can identify strings that meet the "exactly once in each" requirement.

## Complexity

- **Time:** O(n + m)
- **Space:** O(n + m)

## Stats

- Submitted: 2024-08-05 05:42 UTC
- Runtime: 24 ms
- Memory: 24.2 MB
- Language: C++
