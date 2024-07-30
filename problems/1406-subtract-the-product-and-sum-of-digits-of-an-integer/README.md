# Subtract the Product and Sum of Digits of an Integer

**Difficulty:** Easy
**Tags:** math, digit-manipulation, simulation

## Problem

Given a positive integer n (1 ≤ n ≤ 10^5), compute two values: the product of all its digits and the sum of all its digits. Return the difference between the product and the sum.

## Approach

The solution uses a single loop to extract each digit from right to left. It maintains two accumulators: `sum` initialized to 0 and `product` initialized to 1. In each iteration, it extracts the rightmost digit using the modulo operator (`n % 10`), adds it to the running sum, multiplies it into the running product, then removes that digit by integer division (`n /= 10`). The loop continues until all digits have been processed (when n becomes 0). Finally, it returns the difference `product - sum`.

## Complexity

- **Time:** O(log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-30 07:31 UTC
- Runtime: 0 ms
- Memory: 7.4 MB
- Language: C++
