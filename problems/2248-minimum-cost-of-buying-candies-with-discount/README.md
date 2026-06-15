# Minimum Cost of Buying Candies With Discount

**Difficulty:** Easy
**Tags:** greedy, sorting, array

## Problem

Given an array of candy costs, determine the minimum total cost to acquire all candies when a promotion offers every third candy for free. For every two candies purchased, you may choose one additional candy for free, provided its cost does not exceed the minimum cost of the two purchased candies. The goal is to select which candies to buy and which to obtain for free in order to minimize the total expenditure.

## Approach

The solution uses a greedy strategy by sorting the candies in descending order by cost. After sorting, it iterates through the array and processes candies in groups of three. For each group, the two most expensive candies are purchased (indices 0 and 1 of each triplet), and the third most expensive (index 2) is taken for free.

By always buying the most expensive candies and taking the least expensive of each triplet for free, the algorithm maximizes savings. The code identifies free candies using modulo arithmetic: when `i % 3 == 2`, that candy is skipped (not added to the total). All other candies are paid for and added to the running sum.

This greedy approach works because sorting ensures that within each group of three, we pay for the priciest items and get the cheapest one free, which is always optimal given the promotion's constraint that the free candy cannot exceed the minimum cost of the two purchased candies.

## Complexity

- **Time:** O(n log n)
- **Space:** O(1)

## Stats

- Submitted: 2026-06-15 03:30 UTC
- Runtime: 0 ms
- Memory: 17 MB
- Language: C++
