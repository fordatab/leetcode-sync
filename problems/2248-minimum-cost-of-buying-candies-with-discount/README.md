# Minimum Cost of Buying Candies With Discount

**Difficulty:** Easy
**Tags:** greedy, sorting, array

## Problem

Given an array of candy costs, we need to buy all candies while minimizing total cost. The shop offers a promotion: for every two candies purchased, a third candy (with cost not exceeding the minimum of the two purchased) can be taken for free. The array length ranges from 1 to 100, with individual costs between 1 and 100.

## Approach

The solution uses a greedy strategy to maximize savings. It first sorts the candies in descending order by cost. Then it iterates through the sorted array, grouping candies into sets of three. For each group of three consecutive candies (when sorted high to low), the first two are purchased and the third is taken for free. This is implemented by summing all costs except those at positions divisible by 3 with remainder 2 (indices 2, 5, 8, etc.). By sorting in descending order, we ensure that the most expensive candies are purchased while the cheaper ones are obtained for free, minimizing the total cost. The modulo operation elegantly identifies which candies to skip (get for free) in the iteration.

## Complexity

- **Time:** O(n log n)
- **Space:** O(1)

## Stats

- Submitted: 2026-06-15 03:30 UTC
- Runtime: 0 ms
- Memory: 17 MB
- Language: C++
