# Jewels and Stones

**Difficulty:** Easy
**Tags:** hash-set, string, counting

## Problem

Given two strings, one representing jewel types and another representing stones you possess, count how many of your stones are jewels. Each character represents a stone type, and matching is case-sensitive. All jewel types are guaranteed to be distinct, and both strings contain only English letters with lengths between 1 and 50.

## Approach

The solution uses a hash set for efficient lookup. First, it constructs an `unordered_set` containing all characters from the `jewels` string, which provides O(1) average-case lookup time. Then it iterates through each character in the `stones` string, checking if that character exists in the jewel set. For each stone that is found in the set, a counter is incremented. Finally, the total count of matching stones is returned.

## Complexity

- **Time:** O(j + s)
- **Space:** O(j)

## Stats

- Submitted: 2024-07-14 07:01 UTC
- Runtime: 2 ms
- Memory: 8.5 MB
- Language: C++
