# Reorganize String

**Difficulty:** Medium
**Tags:** greedy, heap, priority-queue, hash-table, string

## Problem

Given a string of lowercase letters, rearrange its characters so no two identical characters are adjacent. If such an arrangement is impossible, return an empty string. The string length can be up to 500 characters.

## Approach

The solution uses a greedy approach with a max-heap (priority queue). First, it counts the frequency of each character using a hash map, then pushes all characters into a max-heap ordered by frequency. The algorithm builds the result string character by character: at each step, it attempts to use the most frequent remaining character. If that character matches the last character added to the result, it instead uses the second-most frequent character and pushes the most frequent one back into the heap. This greedy strategy ensures characters are spread out while prioritizing high-frequency characters. The output string is initialized with a dummy '.' character to simplify the adjacency check, which is removed at the end via substring. If at any point the heap becomes empty while a valid character is still needed, the rearrangement is impossible and an empty string is returned.

## Complexity

- **Time:** O(n log k)
- **Space:** O(k)

## Stats

- Submitted: 2026-04-13 22:55 UTC
- Runtime: 0 ms
- Memory: 8.6 MB
- Language: C++
