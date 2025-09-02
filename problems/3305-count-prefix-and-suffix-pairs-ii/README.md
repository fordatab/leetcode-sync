# Count Prefix and Suffix Pairs II

**Difficulty:** Hard
**Tags:** trie, hash-table, string, prefix-suffix-matching

## Problem

Given an array of strings, count how many ordered pairs (i, j) with i < j exist such that words[i] is simultaneously a prefix and a suffix of words[j]. The array can contain up to 10^5 strings, with a total character count across all strings not exceeding 5×10^5.

## Approach

The solution uses a trie structure where each node represents a simultaneous position from both the start and end of a string. Instead of storing 676 child pointers per node, it uses a hash map keyed by a composite index computed as `prefix_char * 26 + suffix_char`, where `prefix_char` is the character at position i from the start and `suffix_char` is the character at position i from the end.

For each word, the algorithm performs two passes:

1. **Search phase**: Traverse the trie following the prefix-suffix character pairs of the current word. At each existing node encountered, add that node's count to the answer (these represent previously inserted words that are both prefix and suffix of the current word).

2. **Insertion phase**: Insert the current word into the trie by creating nodes as needed along its prefix-suffix path, then increment the count at the final node.

This approach efficiently finds all valid pairs by leveraging the fact that if word A is both a prefix and suffix of word B, then at each position i, A[i] must equal B[i] (prefix condition) and A[len(A)-1-i] must equal B[len(B)-1-i] (suffix condition).

## Complexity

- **Time:** O(n * m)
- **Space:** O(n * m)

## Stats

- Submitted: 2025-09-02 01:57 UTC
- Runtime: 619 ms
- Memory: 558.3 MB
- Language: C++
