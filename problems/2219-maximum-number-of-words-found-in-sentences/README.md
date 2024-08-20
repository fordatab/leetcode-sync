# Maximum Number of Words Found in Sentences

**Difficulty:** Easy
**Tags:** string, array, iteration, counting

## Problem

Given an array of sentences where each sentence contains words separated by single spaces, find the maximum number of words that appear in any single sentence. Each sentence has no leading or trailing spaces, and the array can contain up to 100 sentences, each up to 100 characters long.

## Approach

The solution iterates through each sentence in the input array. For each sentence, it counts the number of words by counting spaces and adding one (since n words are separated by n-1 spaces). It initializes a counter `c` to 1 for each sentence, then increments it for every space character found. The maximum count across all sentences is tracked using a variable `m` that is updated after processing each sentence. Finally, it returns the maximum word count found.

## Complexity

- **Time:** O(n * k)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-20 05:30 UTC
- Runtime: 4 ms
- Memory: 13.8 MB
- Language: C++
