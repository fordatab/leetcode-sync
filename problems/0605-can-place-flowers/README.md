# Can Place Flowers

**Difficulty:** Easy
**Tags:** greedy, array, simulation

## Problem

Given a binary array representing a flowerbed where 0 indicates an empty plot and 1 indicates an occupied plot, determine whether n new flowers can be planted such that no two flowers are adjacent. The array length can be up to 20,000, and the input guarantees no existing adjacent flowers.

## Approach

The solution uses a single-pass greedy algorithm that iterates through the flowerbed array. At each position, if a flower exists (value 1), it skips the next position since no flower can be planted there. If the current position is empty (value 0), it checks whether a flower can be planted by examining the next position: if at the array's end or if the next position is also empty, it plants a flower (decrements n) and skips ahead; if the next position has a flower, it skips two positions forward. The logic relies on incrementing the loop variable within the loop body to avoid revisiting positions. Finally, it returns true if all n flowers have been successfully placed (n ≤ 0).

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-13 02:58 UTC
- Runtime: 10 ms
- Memory: 22.8 MB
- Language: C++
