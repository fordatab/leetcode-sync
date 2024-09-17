# Find the XOR of Numbers Which Appear Twice

**Difficulty:** Easy
**Tags:** bit-manipulation, hash-set, xor, math

## Problem

Given an array where each number appears either once or twice, compute the bitwise XOR of all numbers that appear exactly twice. If no number appears twice, return 0. The array has at most 50 elements, each with values between 1 and 50.

## Approach

The solution uses a mathematical property of XOR operations to identify duplicates. First, it creates an unordered set from the input array, which contains each unique number exactly once. Then it performs two XOR accumulations: one over all elements in the original array, and one over all elements in the set. The outer accumulation XORs these two results together.

The key insight is that XOR-ing all array elements gives us (each unique number once) XOR (each duplicate number once more). When we XOR this result with the set (which contains each unique number once), the unique numbers cancel out (since x XOR x = 0), leaving only the XOR of the duplicate numbers.

For example, with `[1,2,2,1]`: XOR of array = 1^2^2^1 = 0, XOR of set = 1^2 = 3, and 0^3 = 3. The duplicates are 1 and 2, and their XOR is indeed 3.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-17 04:42 UTC
- Runtime: 11 ms
- Memory: 28.6 MB
- Language: C++
