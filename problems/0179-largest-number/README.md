# Largest Number

**Difficulty:** Medium
**Tags:** sorting, greedy, string, custom-comparator

## Problem

Given an array of non-negative integers (up to 100 elements, each up to 10^9), arrange them to form the largest possible number when concatenated, returning the result as a string. The challenge is determining the optimal ordering when digits of different numbers can create different outcomes depending on concatenation order.

## Approach

The solution converts all integers to strings for easier manipulation. It then uses a custom comparator to sort these strings: for any two strings `a` and `b`, they are ordered such that `a` comes before `b` if the concatenation `a+b` is lexicographically greater than `b+a`. This ensures that when all strings are concatenated in sorted order, the result is maximized. After sorting and concatenating all strings, the code handles the edge case where all input numbers are zero (which would produce a result starting with '0') by returning "0" instead of multiple zeros.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-26 04:33 UTC
- Runtime: 3 ms
- Memory: 17.5 MB
- Language: C++
