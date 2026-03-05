# Minimize XOR

**Difficulty:** Medium
**Tags:** bit-manipulation, greedy, bitwise-xor

## Problem

Given two positive integers num1 and num2, find a positive integer x that has exactly the same number of set bits (1s in binary) as num2, while minimizing the XOR between x and num1. The constraints guarantee that num1 and num2 are both between 1 and 10^9, and that a unique answer exists.

## Approach

The solution uses a greedy bit-manipulation approach starting with num1 as the initial candidate. First, it counts the set bits in both numbers using `__builtin_popcount`. If num2 has more set bits than num1, the algorithm scans from the least significant bit upward, turning on additional bits in positions that are currently 0 until the total matches num2's count. If num2 has fewer set bits, it scans from the least significant bit upward and turns off bits in positions that are currently 1 until the counts match. This greedy strategy works because:

- To minimize XOR, we want x to be as close to num1 as possible
- When we need more bits, setting lower-order bits (which aren't already set) has minimal impact
- When we need fewer bits, clearing lower-order bits (which are currently set) has minimal impact

The algorithm iterates through at most 32 bit positions, modifying the candidate value bit-by-bit until the desired popcount is achieved.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2026-03-05 01:47 UTC
- Runtime: 0 ms
- Memory: 8 MB
- Language: C++
