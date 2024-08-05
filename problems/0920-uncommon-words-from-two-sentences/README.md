# Uncommon Words from Two Sentences

**Difficulty:** Easy
**Tags:** hash-table, string, counting

## Problem

Given two sentences composed of lowercase words separated by spaces, identify all words that appear exactly once across both sentences combined. A word qualifies as uncommon if its total occurrence count in both sentences is exactly one. The sentences can be up to 200 characters each, and the result can be returned in any order.

## Approach

The solution concatenates both sentences into a unified frequency analysis. It appends a space to each sentence to simplify parsing, then uses a hash map to count occurrences of every word across both inputs.

For each sentence, it iterates through using `find()` to locate space delimiters, extracting substrings between consecutive spaces and incrementing their counts in the map. The `prev` pointer tracks the starting position of each word extraction.

After processing both sentences, it scans the frequency map and collects all words with a count of exactly 1. These are the words that appear once total (either once in one sentence and zero times in the other, or cannot appear more than once combined).

## Complexity

- **Time:** O(n + m)
- **Space:** O(n + m)

## Stats

- Submitted: 2024-08-05 05:52 UTC
- Runtime: 3 ms
- Memory: 9 MB
- Language: C++
