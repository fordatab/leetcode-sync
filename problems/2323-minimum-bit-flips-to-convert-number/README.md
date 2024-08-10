# Minimum Bit Flips to Convert Number

**Difficulty:** Easy
**Tags:** bit-manipulation, hamming-distance

## Problem

Given two non-negative integers start and goal (each up to 10^9), determine the minimum number of bit flips needed to transform start into goal. A bit flip changes a single bit from 0 to 1 or vice versa in the binary representation.

## Approach

The solution iterates through all 32 bit positions (sufficient for integers up to 10^9) and compares the corresponding bits of start and goal. For each position, it extracts the bit using right shift and bitwise AND with 1. When the bits at the same position differ between start and goal, it increments a counter. The final count represents the total number of differing bits, which is the minimum number of flips required. This is effectively computing the Hamming distance between the two numbers.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-10 02:55 UTC
- Runtime: 0 ms
- Memory: 7.7 MB
- Language: C++
