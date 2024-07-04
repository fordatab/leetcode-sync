# Best Time to Buy and Sell Stock

**Difficulty:** Easy
**Tags:** two-pointers, sliding-window, greedy, array

## Problem

Given an array of stock prices where each element represents the price on a specific day, find the maximum profit achievable by buying on one day and selling on a strictly later day. If no profitable transaction exists, return 0. The array can contain up to 100,000 elements with prices ranging from 0 to 10,000.

## Approach

The solution uses a two-pointer sliding window technique to track potential buy and sell days. The left pointer `l` represents the potential buying day (tracking the minimum price seen so far), while the right pointer `r` represents the potential selling day. As we iterate through the array:

- At each step, we calculate the profit from buying at `l` and selling at `r`, updating our maximum profit if this transaction is better.
- If the price at `r` is lower than the price at `l`, we've found a new potential minimum buying price, so we move `l` to `r` (since buying at this lower price could yield better future profits).
- Otherwise, we just advance `r` to explore the next selling opportunity.

This single-pass approach ensures we consider all valid buy-sell pairs while maintaining the constraint that the sell day must come after the buy day.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-04 05:54 UTC
- Runtime: 69 ms
- Memory: 95.7 MB
- Language: C++
