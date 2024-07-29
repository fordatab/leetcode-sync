# Successful Pairs of Spells and Potions

**Difficulty:** Medium
**Tags:** binary-search, sorting, array, two-pointers

## Problem

Given two arrays of positive integers representing spell and potion strengths, along with a success threshold, determine for each spell how many potions it can pair with such that their product meets or exceeds the threshold. The arrays can contain up to 100,000 elements each, with individual values up to 100,000, and the success threshold can be as large as 10^10.

## Approach

The solution sorts the potions array once at the beginning, then for each spell performs a binary search to find the leftmost potion that creates a successful pair.

For each spell, binary search maintains left and right pointers on the sorted potions array. At each step, it computes the product of the current spell with the middle potion (using `long long` to avoid overflow). If this product meets or exceeds the success threshold, the search continues in the left half to find an earlier qualifying potion; otherwise, it searches the right half.

After the binary search converges, the left pointer indicates the first position where all subsequent potions form successful pairs. The count of successful pairs is therefore `potions.size() - l`, which is appended to the result array.

## Complexity

- **Time:** O(m log m + n log m)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-29 07:57 UTC
- Runtime: 146 ms
- Memory: 103.7 MB
- Language: C++
