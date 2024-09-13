# Convert Date to Binary

**Difficulty:** Easy
**Tags:** string, math, bit-manipulation

## Problem

Given a date string in 'yyyy-mm-dd' format, convert each component (year, month, day) to its binary representation without leading zeros and return them joined with hyphens. The input is guaranteed to be a valid Gregorian calendar date between January 1, 1900 and December 31, 2100.

## Approach

The solution splits the date string into three components using `substr()`: year (first 4 characters), month (2 characters starting at index 5), and day (2 characters starting at index 8). Each substring is converted to an integer using `stoi()`, then passed to a helper function `binaryConversion()` that performs manual binary conversion.

The `binaryConversion()` helper repeatedly divides the number by 2, prepending each remainder (0 or 1) to the result string until the number becomes zero. It handles the special case of 1 directly. The three binary strings are then concatenated with hyphens between them to form the final result.

This approach manually implements binary conversion rather than using built-in functions, building the binary string from right to left by extracting digits through modulo and division operations.

## Complexity

- **Time:** O(log n)
- **Space:** O(log n)

## Stats

- Submitted: 2024-09-13 10:15 UTC
- Runtime: 4 ms
- Memory: 11.1 MB
- Language: C++
