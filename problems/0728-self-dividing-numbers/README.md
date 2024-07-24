# Self Dividing Numbers

**Difficulty:** Easy
**Tags:** math, digit-manipulation, brute-force, iteration

## Problem

Find all numbers in a given range [left, right] where each number is divisible by every digit it contains. Numbers containing the digit zero are automatically excluded since division by zero is undefined. The range is constrained to values between 1 and 10,000.

## Approach

The solution iterates through every number in the range [left, right] and tests each one for the self-dividing property using a helper function.

The `div` helper function checks if a number is self-dividing by:
- Storing the original number in variable `c`
- Extracting each digit using modulo 10 operation (`x % 10`)
- Immediately rejecting if any digit is zero
- Testing if the original number `c` is divisible by the current digit
- Moving to the next digit by integer division (`x /= 10`)

For each number that passes the `div` check, it's added to the result vector. The iteration continues until all numbers in the range have been tested.

## Complexity

- **Time:** O(n * d)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-24 00:32 UTC
- Runtime: 4 ms
- Memory: 7.9 MB
- Language: C++
