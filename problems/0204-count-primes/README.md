# Count Primes

**Difficulty:** Medium
**Tags:** sieve-of-eratosthenes, array, math, prime-numbers

## Problem

Given an integer n, count how many prime numbers exist below n (not including n itself). The input can range from 0 to 5 million, so an efficient algorithm is necessary to handle large values.

## Approach

This solution implements the Sieve of Eratosthenes algorithm. It starts by creating a boolean vector of size n, initially marking all numbers as potentially prime (true). The algorithm iterates through numbers from 2 up to the square root of n. For each number p that is still marked as prime, it marks all multiples of p starting from p² as composite (false), since smaller multiples would have been marked by earlier primes. After sieving, the algorithm counts how many positions from index 2 to n-1 remain marked as true, which represents the count of primes below n. Early termination handles edge cases where n ≤ 2, returning 0 since there are no primes below 2.

## Complexity

- **Time:** O(n log log n)
- **Space:** O(n)

## Stats

- Submitted: 2026-05-05 04:46 UTC
- Runtime: 196 ms
- Memory: 12.8 MB
- Language: C++
