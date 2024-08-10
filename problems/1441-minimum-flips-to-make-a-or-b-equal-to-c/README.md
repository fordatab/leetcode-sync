# Minimum Flips to Make a OR b Equal to c

**Difficulty:** Medium
**Tags:** bit-manipulation, bitwise-operations, greedy

## Problem

Given three positive integers a, b, and c, determine the minimum number of bit flips needed in a and b such that the bitwise OR of a and b equals c. A flip changes a single bit from 0 to 1 or from 1 to 0. The integers can be as large as 10^9, requiring consideration of up to 30 significant bits.

## Approach

The solution examines each of the 32 bit positions independently, comparing the corresponding bits of a, b, and c. For each position, it extracts the least significant bit using modulo 2, then determines the required flips:

- When the target bit in c is 0, both corresponding bits in a and b must be 0. The solution adds the count of 1-bits in a and b at this position (since each 1 needs to be flipped to 0).
- When the target bit in c is 1, at least one of the bits in a or b must be 1. If both are currently 0, exactly one flip is needed to make their OR equal 1.

After processing each bit position, the solution shifts all three numbers right by dividing by 2, effectively moving to the next bit position. The total count of required flips across all 32 positions is returned.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-10 02:51 UTC
- Runtime: 2 ms
- Memory: 7.2 MB
- Language: C++
