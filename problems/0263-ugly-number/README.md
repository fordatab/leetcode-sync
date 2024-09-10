# Ugly Number

**Difficulty:** Easy
**Tags:** math, number-theory, iteration

## Problem

Given a positive integer n, determine whether it can be expressed using only the prime factors 2, 3, and 5. Numbers that satisfy this condition (having no prime factors other than 2, 3, and 5) are called "ugly numbers". The input range includes negative numbers and zero, which should return false, while 1 is considered an ugly number by convention.

## Approach

The solution repeatedly divides the input number by 2, 3, 4, and 5 using a loop with index i from 2 to 5. For each divisor, it performs integer division as many times as possible while the number is divisible by that divisor. After exhausting all divisions by these values, the solution checks if the remaining number equals 1.

The key insight is that if n can be completely factored into only 2s, 3s, and 5s, then after removing all these factors, exactly 1 should remain. If any other prime factor exists, the number will be greater than 1 after this process.

Note that the loop iterates through i=2,3,4,5, where dividing by 4 is redundant since 4=2² and all factors of 2 were already removed when i=2. The short-circuit condition `n` in the loop prevents division by zero when n becomes 0 (for non-positive inputs). Non-positive numbers will result in n != 1, correctly returning false.

## Complexity

- **Time:** O(log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-10 18:56 UTC
- Runtime: 0 ms
- Memory: 7.3 MB
- Language: C++
