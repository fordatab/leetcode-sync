# Watering Plants

**Difficulty:** Medium
**Tags:** array, greedy, simulation

## Problem

Given an array of plants where each element represents the water needed for that plant, and a watering can with a fixed capacity, determine the total number of steps required to water all plants in left-to-right order. You start at position -1 (a river), and must return to the river to refill whenever your current water is insufficient to completely water the next plant. Each unit of distance costs one step.

## Approach

The solution uses a single-pass greedy simulation. It maintains a variable `c` tracking the current water in the can (initially full at `capacity`). For each plant at index `x`, it checks whether the remaining water `c` is sufficient. If not, it refills by returning to the river and walking back, adding `2*x + 1` steps (x steps back to river, x steps forward to plant, plus 1 more to reach it). If the current water suffices, it simply adds 1 step to move forward. After handling each plant, it deducts the plant's water requirement from `c`. The algorithm accumulates all steps in the `out` variable and returns it after processing all plants.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-28 09:39 UTC
- Runtime: 11 ms
- Memory: 11.1 MB
- Language: C++
