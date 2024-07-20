# Implement Trie (Prefix Tree)

**Difficulty:** Medium
**Tags:** trie, hash-table, string, design

## Problem

Build a prefix tree data structure that supports three operations: adding strings, checking if a complete string exists, and checking if any stored string begins with a given prefix. Input strings and prefixes contain only lowercase English letters with lengths up to 2000 characters, and the system must handle up to 30,000 total operations across all three methods.

## Approach

The solution implements a classic trie using nodes that each contain an array of 26 pointers (one for each lowercase letter) and a boolean flag indicating whether that node marks the end of a complete word.

**Insertion** walks character-by-character through the word, creating new nodes as needed by indexing into the children array using `c-'a'` to map letters to positions 0-25, then marks the final node as a word endpoint.

**Search** follows the same traversal pattern but returns false immediately if any character's child pointer is null, and only returns true if we reach the end AND that node is marked as a word endpoint.

**Prefix matching** uses identical traversal logic to search but returns true as soon as we successfully traverse all prefix characters, regardless of the `isWord` flag, since we only care whether the path exists.

## Complexity

- **Time:** O(m)
- **Space:** O(n * m)

## Stats

- Submitted: 2024-07-20 02:12 UTC
- Runtime: 40 ms
- Memory: 48.5 MB
- Language: C++
