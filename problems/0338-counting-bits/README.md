# Counting Bits

**Difficulty:** Easy
**Tags:** bit-manipulation, counting, array

## Problem

Given a non-negative integer n, create an array of length n+1 where each element at index i contains the count of 1-bits in the binary representation of i. The input range is 0 to 100,000, and the solution should efficiently compute bit counts for all numbers from 0 through n.

## Approach

The solution uses a straightforward bit-counting approach with a helper function. For each number from 0 to n, it calls the `bits` helper function which manually counts set bits by repeatedly checking the least significant bit (using bitwise AND with 1) and right-shifting until the number becomes zero. Each iteration increments a counter if the LSB is 1, effectively counting all 1-bits in the binary representation. The results are stored in a pre-allocated vector and returned.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-20 07:16 UTC
- Runtime: 3 ms
- Memory: 9.3 MB
- Language: C++
