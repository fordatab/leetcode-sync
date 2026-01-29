# Design Search Autocomplete System

**Difficulty:** Hard
**Tags:** trie, hash-table, heap, design, string

## Problem

Build an autocomplete system that suggests up to three matching sentences as a user types character by character. Each sentence in the historical dataset has a frequency count indicating how many times it was previously entered. When the user types a character (other than '#'), return the top three sentences that start with the accumulated prefix, ranked first by frequency (descending) and then lexicographically (ascending) if frequencies tie. When the user types '#', store the completed sentence (updating its frequency if it already exists) and reset for a new query. The system must handle up to 100 initial sentences, each up to 100 characters, and up to 5000 input calls.

## Approach

The solution uses a **trie** (prefix tree) where each node stores a set of complete sentences that pass through it, along with a map of child pointers keyed by character. During initialization, each historical sentence is inserted into the trie: at every character node along the path, the full sentence is added to that node's `words` set, and a global hash map (`mp`) tracks the frequency of each sentence.

When `input(c)` is called with a non-'#' character, the code appends `c` to `currentInput` and then traverses the trie from the root following the path defined by `currentInput`. If the path exists, the node reached contains a set of all sentences that share that prefix. The `topThree` helper function then uses a min-heap (priority queue) of size at most three to find the top three sentences by frequency (higher is better) with lexicographic tiebreaking (lower ASCII order is better). The heap ensures that as candidates are processed, only the best three are retained.

When the user types '#', the accumulated `currentInput` is inserted into the trie (adding it to the `words` set at each node along its path), its frequency in `mp` is incremented, and `currentInput` is cleared for the next query. An empty list is returned for the '#' input.

## Complexity

- **Time:** O(L + k log 3)
- **Space:** O(N * L)

## Stats

- Submitted: 2026-01-29 01:27 UTC
- Runtime: 217 ms
- Memory: 270.9 MB
- Language: C++
