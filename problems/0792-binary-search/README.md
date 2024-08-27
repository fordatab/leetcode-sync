# Binary Search

**Difficulty:** Easy
**Tags:** binary-search, recursion, divide-and-conquer, array

## Problem

Given a sorted array of unique integers and a target value, find the index of the target in the array. If the target is not present, return -1. The array can contain up to 10,000 elements with values ranging from -10,000 to 10,000, and the solution must run in logarithmic time.

## Approach

This solution implements a classic recursive binary search algorithm. The main function `search/2` initializes the search by calling a helper function `search/4` with the initial left bound (0) and right bound (length - 1).

The recursive helper function `search/4` calculates the midpoint using `(Left + Right) div 2` to avoid integer overflow. It then uses `lists:nth/2` to retrieve the element at the middle position (adding 1 because Erlang lists are 1-indexed). 

Depending on the comparison with the target, the function either returns the current index if a match is found, recursively searches the right half if the middle value is too small, or searches the left half if the middle value is too large. The recursion terminates when the search space is exhausted (Left > Right), at which point -1 is returned.

## Complexity

- **Time:** O(log n)
- **Space:** O(log n)

## Stats

- Submitted: 2024-08-27 23:55 UTC
- Runtime: 376 ms
- Memory: 78.4 MB
- Language: Erlang
