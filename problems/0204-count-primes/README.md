# Count Primes

**Difficulty:** Medium
**Tags:** sieve-of-eratosthenes, prime-numbers, precomputation, memoization, array

## Problem

Given a non-negative integer n (up to 5 million), count how many prime numbers exist that are strictly smaller than n. For example, if n is 10, the answer is 4 because the primes less than 10 are 2, 3, 5, and 7.

## Approach

This solution uses the Sieve of Eratosthenes algorithm with static memoization to precompute all prime counts up to 5 million on the first invocation. The static initializer creates a boolean array marking which numbers are prime: it starts by assuming all numbers are prime, then for each prime i starting from 2, it marks all multiples of i (beginning at i²) as composite. After sieving, a cumulative count array is built where `count[i]` stores the total number of primes up to and including i. On subsequent calls, the function simply performs an O(1) lookup into this precomputed array, returning `primeCount[n-1]` which gives the count of primes strictly less than n. Edge cases where n ≤ 2 return 0 directly since there are no primes less than 2.

## Complexity

- **Time:** O(M log log M)
- **Space:** O(M)

## Stats

- Submitted: 2026-05-05 04:47 UTC
- Runtime: 39 ms
- Memory: 30.7 MB
- Language: C++
