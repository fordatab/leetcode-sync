# Sort Array by Increasing Frequency

**Difficulty:** Easy
**Tags:** hash-table, sorting, counting, custom-comparator

## Problem

Given an integer array, sort it so that elements appear in order of increasing frequency (least frequent first). When two elements have the same frequency, they should appear in decreasing numerical order. The array has at most 100 elements with values between -100 and 100.

## Approach

The solution uses a frequency-counting approach with custom sorting. First, it counts the occurrence of each number using an unordered hash map. Then it creates a vector of pairs where each pair contains (frequency, value). A custom comparator sorts these pairs primarily by frequency in ascending order, and secondarily by value in descending order when frequencies match. Finally, it reconstructs the output array by iterating through the sorted pairs and appending each value the appropriate number of times based on its frequency.

## Complexity

- **Time:** O(n log k)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-23 01:58 UTC
- Runtime: 5 ms
- Memory: 15.3 MB
- Language: C++
