# Number of Bit Changes to Make Two Integers Equal

**Difficulty:** Easy
**Tags:** bit-manipulation, bitwise-operations, math

## Problem

Given two positive integers n and k, determine the minimum number of bit flips needed to transform n into k, where you can only change bits from 1 to 0 (never from 0 to 1). If the transformation is impossible, return -1. The integers are constrained to be between 1 and 10^6.

## Approach

The solution performs a bit-by-bit comparison of n and k across all 32 bit positions. For each bit position, it extracts the corresponding bit from both numbers using right shift and bitwise AND operations.

The key insight is that transformation is only possible if k doesn't have any 1-bits where n has 0-bits, since we can only turn bits off, not on. If we find a position where k has a 1-bit but n has a 0-bit, we immediately return -1.

For positions where n has a 1-bit and k has a 0-bit, we increment a counter since this represents a required bit flip. The final count represents the minimum number of changes needed.

The algorithm also handles two special cases upfront: if n equals k (return 0), and if k is greater than n (return -1, since turning bits off can only decrease or maintain the value).

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-21 02:44 UTC
- Runtime: 0 ms
- Memory: 8.2 MB
- Language: C++
