# Boats to Save People

**Difficulty:** Medium
**Tags:** two-pointers, greedy, sorting, array

## Problem

Given an array of person weights and a weight limit, determine the minimum number of boats needed to transport everyone. Each boat can carry at most two people, and the combined weight of passengers cannot exceed the limit. The array can contain up to 50,000 people, with weights ranging from 1 to the limit (up to 30,000).

## Approach

The solution uses a two-pointer greedy approach after sorting the weights. First, the array is sorted in ascending order. Two pointers are initialized: one at the start (lightest person) and one at the end (heaviest person).

For each boat, the algorithm always takes the heaviest remaining person (from the right pointer). Then it checks if the lightest remaining person (from the left pointer) can also fit on the same boat without exceeding the limit. If both can fit together, the left pointer advances; otherwise, the heavy person travels alone.

The boat count increments with each iteration, and the process continues until all people are assigned to boats. This greedy strategy works because pairing the heaviest with the lightest (when possible) minimizes wasted capacity and maximizes the chance of future pairings.

## Complexity

- **Time:** O(n log n)
- **Space:** O(log n)

## Stats

- Submitted: 2025-12-04 03:21 UTC
- Runtime: 1076 ms
- Memory: 45.8 MB
- Language: C++
