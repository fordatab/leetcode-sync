# Sum of Values at Indices With K Set Bits

**Difficulty:** Easy
**Tags:** bit-manipulation, array, simulation

## Problem

Given a zero-indexed integer array and a target count k, find the sum of all array elements whose indices have exactly k bits set to 1 in their binary representation. The array can have up to 1000 elements, values up to 100,000, and k ranges from 0 to 10.

## Approach

The solution iterates through each index of the input array. For each index, it counts the number of set bits (1s) in the binary representation by repeatedly checking the least significant bit using a bitwise AND operation with 1, then right-shifting the number. A counter accumulates the number of set bits found. After processing all bits of the index, if the count equals k, the corresponding array element is added to the result sum. This process continues for all indices, and the accumulated sum is returned.

## Complexity

- **Time:** O(n log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-18 04:02 UTC
- Runtime: 3 ms
- Memory: 25 MB
- Language: C++
