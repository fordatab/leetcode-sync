# Majority Element

**Difficulty:** Easy
**Tags:** array, boyer-moore-voting, counting

## Problem

Given an array of integers, find and return the element that appears more than ⌊n/2⌋ times, where n is the array length. The input guarantees that such a majority element always exists. The array can contain up to 50,000 elements with values ranging from -10^9 to 10^9.

## Approach

This solution implements the Boyer-Moore voting algorithm. It maintains a candidate element and a counter. The algorithm iterates through the array once: whenever the counter reaches zero, it selects the current element as the new candidate. For each subsequent element, if it matches the candidate, the counter is incremented; otherwise, the counter is decremented.

The key insight is that if an element appears more than n/2 times, it will survive the voting process. Each occurrence of the majority element can be thought of as canceling out one occurrence of a different element, and since the majority element appears more frequently, it will remain as the candidate after all cancellations.

Since the problem guarantees a majority element exists, no verification step is needed after the single pass through the array.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-01 04:50 UTC
- Runtime: 11 ms
- Memory: 26.9 MB
- Language: C++
