# Find the Count of Numbers Which Are Not Special

**Difficulty:** Medium
**Tags:** math, number-theory, prime-numbers, square-root

## Problem

Given a range [l, r], count how many numbers are not "special." A number is special if it has exactly 2 proper divisors (divisors excluding the number itself). The range can be as large as 1 to 10^9, requiring an efficient approach rather than checking each number individually.

## Approach

The solution recognizes that a number has exactly 2 proper divisors only if it's the square of a prime number. For example, p² has divisors {1, p, p²}, so excluding p² itself leaves exactly 2 proper divisors: 1 and p.

The algorithm:
1. Computes the square roots of the range boundaries (l and r)
2. Determines the range of potential prime bases by taking the ceiling of √l and floor of √r
3. Counts how many primes exist in this range using a standard primality test that checks divisibility up to √n
4. Returns the total count of numbers in [l, r] minus the count of special numbers (prime squares)

The primality check optimizes by testing divisibility by 2 and 3 first, then checking only numbers of the form 6k±1 up to the square root.

## Complexity

- **Time:** O(√r · √(√r)) = O(r^(3/4))
- **Space:** O(1)

## Stats

- Submitted: 2024-07-28 03:13 UTC
- Runtime: 21 ms
- Memory: 8.4 MB
- Language: C++
