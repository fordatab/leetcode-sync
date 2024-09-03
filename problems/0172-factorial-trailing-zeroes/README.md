# Factorial Trailing Zeroes

**Difficulty:** Medium
**Tags:** math, recursion, number-theory

## Problem

Given a non-negative integer n (where 0 ≤ n ≤ 10⁴), determine how many trailing zeros appear at the end of n factorial. A trailing zero is produced by factors of 10, which come from pairs of 2 and 5 in the prime factorization of n!.

## Approach

The solution uses a recursive approach to count factors of 5 in n!. Since trailing zeros come from pairs of 2 and 5, and there are always more factors of 2 than 5 in any factorial, we only need to count how many times 5 appears as a factor.

The recursion works by:
1. Base case: if n is 0, return 0
2. Divide n by 5 to count multiples of 5 (contributes one factor of 5 each)
3. Recursively call with n/5 to count multiples of 25 (contributes an additional factor of 5), 125 (another additional factor), and so on
4. Sum all these contributions

For example, with n=25: we get 25/5 = 5 multiples of 5, plus trailingZeroes(5) which gives 5/5 = 1 multiple of 25, for a total of 6 trailing zeros. This effectively counts ⌊n/5⌋ + ⌊n/25⌋ + ⌊n/125⌋ + ...

## Complexity

- **Time:** O(log n)
- **Space:** O(log n)

## Stats

- Submitted: 2024-09-03 06:13 UTC
- Runtime: 4 ms
- Memory: 7.8 MB
- Language: C++
