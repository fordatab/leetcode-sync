# Kth Distinct String in an Array

**Difficulty:** Easy
**Tags:** hash-table, ordered-map, string, counting

## Problem

Given an array of strings and an integer k, find the kth string that appears exactly once in the array, preserving the order of first appearance. If fewer than k such unique strings exist, return an empty string. The task requires identifying strings with a frequency of one and returning the kth one in their original sequence.

## Approach

The solution uses two passes over the input array. First, it builds a frequency map using an unordered_map to count occurrences of each string. In the second pass, it iterates through the array in order, and whenever it finds a string with frequency 1, it stores that string in an ordered map (keyed by its index) to maintain the original order. Once k distinct strings have been found, the loop terminates early. Finally, if fewer than k distinct strings exist, it returns an empty string; otherwise, it retrieves the last inserted entry from the ordered map using a reverse iterator, which corresponds to the kth distinct string.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-05 05:35 UTC
- Runtime: 24 ms
- Memory: 20 MB
- Language: C++
