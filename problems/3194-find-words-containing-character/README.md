# Find Words Containing Character

**Difficulty:** Easy
**Tags:** string, array, linear-search

## Problem

Given an array of strings and a target character, find all indices of strings that contain the target character. The input consists of up to 50 words, each up to 50 characters long, containing only lowercase English letters. The output can be in any order.

## Approach

The solution iterates through each word in the input array using an index-based loop. For each word at position `i`, it uses the `find()` method of the string class to check if the target character `x` appears anywhere in the word. The `find()` method returns `std::string::npos` if the character is not found. When a word contains the character (i.e., `find()` returns something other than `npos`), the index `i` is added to the output vector. After checking all words, the accumulated indices are returned.

## Complexity

- **Time:** O(n * m)
- **Space:** O(k)

## Stats

- Submitted: 2024-07-22 11:21 UTC
- Runtime: 14 ms
- Memory: 33.9 MB
- Language: C++
