# Smallest Even Multiple

**Difficulty:** Easy
**Tags:** math, number-theory, least-common-multiple

## Problem

Given a positive integer n (1 ≤ n ≤ 150), find the smallest positive integer that is divisible by both 2 and n. In other words, find the least common multiple of 2 and n.

## Approach

The solution uses a simple iterative approach based on the observation that if n is already even, it's divisible by 2 and thus is the answer. If n is odd, we need to find the smallest even multiple of n.

The code enters a while loop that checks if n is odd (n % 2 == 1). While n remains odd, it doubles n by adding n to itself (n += n). This effectively transforms an odd n into 2n, which is guaranteed to be even and divisible by the original n.

Once n becomes even (either it was even initially or after one doubling operation), the loop exits and returns n. For odd inputs, this returns 2n; for even inputs, it returns n unchanged.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-22 22:10 UTC
- Runtime: 0 ms
- Memory: 7.6 MB
- Language: C++
