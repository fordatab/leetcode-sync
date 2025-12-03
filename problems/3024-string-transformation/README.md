# String Transformation

**Difficulty:** Hard
**Tags:** string, kmp, matrix-exponentiation, modular-arithmetic, pattern-matching, combinatorics

## Problem

Given two equal-length strings s and t and an integer k, determine how many ways you can transform s into t using exactly k operations. Each operation removes a suffix of length l (where 0 < l < n) from s and prepends it to the front. The answer should be returned modulo 10^9 + 7. Constraints include string lengths up to 5×10^5 and k up to 10^15.

## Approach

The solution uses KMP pattern matching combined with matrix exponentiation-based recurrence.

First, it constructs the doubled string s+s (minus the last character to avoid a full cycle duplication) and uses KMP to find all positions where t appears. Each such position represents a valid rotation index — a shift amount that would make s equal to t after some number of operations.

The key insight is that the number of ways to reach a particular rotation in exactly k steps follows a linear recurrence. The code distinguishes between two cases: rotations at position 0 (the identity, where s is already at rotation 0) and rotations at any other valid position. It computes closed-form formulas f_k[0] and f_k[1] using modular exponentiation of (n-1) to the power k, which effectively solves the recurrence in O(log k) time.

The formula includes modular inverse computation (pow(n, M-2, M) applies Fermat's little theorem) and adjusts based on whether k is even or odd (k % 2 * 2 - 1 gives -1 for even k and +1 for odd k). Finally, it accumulates the answer by summing f_k[!!p] for each valid rotation position p found by KMP, where !!p converts position 0 to index 0 and any other position to index 1.

## Complexity

- **Time:** O(n log k)
- **Space:** O(n)

## Stats

- Submitted: 2025-12-03 09:35 UTC
- Runtime: 50 ms
- Memory: 62 MB
- Language: C++
