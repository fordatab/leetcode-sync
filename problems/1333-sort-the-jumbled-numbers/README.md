# Sort the Jumbled Numbers

**Difficulty:** Medium
**Tags:** sorting, array, string, stable-sort

## Problem

Given a digit mapping array and an array of integers, sort the integers based on their "mapped values" where each digit in a number is replaced according to the mapping. Numbers with identical mapped values must maintain their original relative order (stable sort), and the output should contain the original numbers, not their mapped versions. The mapping array has exactly 10 elements, nums can have up to 30,000 integers, and each integer can be up to 10^9.

## Approach

The solution converts each number to its mapped value by transforming it to a string, replacing each digit character using the mapping array, and converting back to an integer. It stores pairs of (mapped_value, original_index) in a vector to preserve the original ordering information. After sorting these pairs, the sort is naturally stable because pairs with equal first elements maintain their relative order based on their second element (the index). Finally, it reconstructs the output by retrieving the original numbers using the sorted indices.

The key steps are:
- For each number, convert to string and map each digit character by looking up `mapping[digit]`
- Store both the mapped integer value and the original index as a pair
- Sort the pairs (C++ stable_sorts pairs lexicographically, so equal mapped values stay in index order)
- Build the result by fetching original numbers via the sorted indices

## Complexity

- **Time:** O(n log n + d*n)
- **Space:** O(n + d)

## Stats

- Submitted: 2024-07-24 19:35 UTC
- Runtime: 187 ms
- Memory: 84 MB
- Language: C++
