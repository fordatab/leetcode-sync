# Count Primes

**Difficulty:** Medium
<<<<<<< HEAD
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
=======
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
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d
- Language: C++
