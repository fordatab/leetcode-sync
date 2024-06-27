# Group Anagrams

**Difficulty:** Medium
**Tags:** hash-table, string, counting, array

## Problem

Given an array of strings, partition them into groups where each group contains strings that are anagrams of one another. Anagrams are words formed by rearranging the letters of another word. The input can contain up to 10,000 strings, each up to 100 characters long, all using lowercase English letters only.

## Approach

The solution uses a hash map (defaultdict) where each key represents a unique character frequency signature. For each input string, it constructs a 26-element array counting the occurrences of each letter ('a' through 'z'). This count array is converted to a tuple to serve as a hashable key. All strings with identical character frequencies—meaning they're anagrams—map to the same key and are collected in the same list. Finally, the values of the hash map (the grouped lists) are returned.

The key insight is that anagrams share identical character frequency distributions. By using the frequency tuple as a dictionary key, the solution automatically groups anagrams together in a single pass through the input array.

## Complexity

- **Time:** O(n * k)
- **Space:** O(n * k)

## Stats

- Submitted: 2024-06-27 05:04 UTC
- Runtime: 105 ms
- Memory: 22.3 MB
- Language: Python3
