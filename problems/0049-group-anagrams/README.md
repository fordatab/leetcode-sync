# Group Anagrams

**Difficulty:** Medium
**Tags:** hash-table, string, sorting, anagram

## Problem

Given an array of strings, organize them into groups where each group contains strings that are anagrams of each other (strings that can be rearranged to form one another). The input can contain up to 10,000 strings, each up to 100 characters long, consisting only of lowercase English letters. The output groups can be returned in any order.

## Approach

The solution uses a hash map to group anagrams by a canonical representation. For each string in the input array, it creates a sorted version of that string which serves as a unique key — all anagrams will produce the same sorted string. The code iterates through each input string, sorts its characters, and uses this sorted string as a key in an `unordered_map`. The original (unsorted) string is then appended to the vector associated with that key. After processing all strings, the solution extracts all value vectors from the map and returns them as the final result. The key insight is that sorting normalizes anagrams to an identical representation, allowing efficient grouping via hash table lookups.

## Complexity

- **Time:** O(n * k log k)
- **Space:** O(n * k)

## Stats

- Submitted: 2024-06-27 04:14 UTC
- Runtime: 24 ms
- Memory: 25 MB
- Language: C++
