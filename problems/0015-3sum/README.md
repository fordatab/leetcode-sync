# 3Sum

**Difficulty:** Medium
**Tags:** two-pointers, sorting, array

## Problem

Find all unique triplets in an integer array that sum to zero. The array can contain up to 3000 elements with values ranging from -100,000 to 100,000. Each triplet must use three distinct indices, and the result must not contain duplicate triplets.

## Approach

The solution first sorts the input array to enable two-pointer searching and duplicate handling. For each element that could be the first element of a triplet (non-positive values only, since three positive numbers can't sum to zero), it transforms the problem into finding two numbers that sum to the negation of the current element.

The inner search uses two pointers: one starting just after the current element (left) and one at the array end (right). These pointers move toward each other, adjusting based on whether their sum is too small or too large compared to the target.

Duplicate triplets are avoided through two mechanisms: skipping consecutive identical values when selecting the first element, and advancing past duplicates when a valid pair is found. When the two-pointer sum matches the target, both pointers skip over any duplicate values before continuing the search.

## Complexity

- **Time:** O(n^2)
- **Space:** O(1)

## Stats

- Submitted: 2024-06-30 07:52 UTC
- Runtime: 63 ms
- Memory: 27.1 MB
- Language: C++
