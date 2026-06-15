# Majority Element II

**Difficulty:** Medium
**Tags:** array, boyer-moore, voting-algorithm, two-pointer

## Problem

Given an array of n integers, identify all elements that occur more than ⌊n/3⌋ times. The array size ranges from 1 to 50,000 elements, and values can be any integer from -10^9 to 10^9. At most two elements can satisfy this frequency threshold in any array.

## Approach

This solution implements the Boyer-Moore majority vote algorithm extended for finding elements with frequency greater than n/3. 

In the first pass, it maintains two candidate elements and their counts. For each element, if it matches an existing candidate, its count increments; if a count is zero, that slot is claimed by the current element; otherwise, both counts decrement (voting out both candidates). This pairing mechanism ensures that if elements appear more than n/3 times, they will survive as candidates.

The second pass verifies the candidates by counting their actual occurrences in the array. Only candidates whose frequency exceeds n/3 are added to the result. This validation is necessary because the first pass only guarantees that true majority elements won't be eliminated, not that the final candidates are definitely majority elements.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-06-15 04:12 UTC
- Runtime: 0 ms
- Memory: 23.6 MB
- Language: C++
