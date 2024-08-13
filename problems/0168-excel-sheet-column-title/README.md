# Excel Sheet Column Title

**Difficulty:** Easy
**Tags:** math, string, base-conversion

## Problem

Given a positive integer representing a column number, convert it to the alphabetical column label used in spreadsheet applications (A=1, B=2, ..., Z=26, AA=27, etc.). The input ranges from 1 to 2^31 - 1.

## Approach

The solution treats this as a base-26 numeral system conversion with a crucial adjustment: since there's no zero in the column system (it starts at 1, not 0), we decrement the column number before each digit extraction. In each iteration, the code decrements the number, computes the remainder modulo 26 to determine the current letter (where 0 maps to 'A' and 25 maps to 'Z'), appends that character to the result string, and divides by 26 to shift to the next position. The digits are built in reverse order (least significant to most significant), so the final step reverses the entire string before returning it.

## Complexity

- **Time:** O(log n)
- **Space:** O(log n)

## Stats

- Submitted: 2024-08-13 03:42 UTC
- Runtime: 2 ms
- Memory: 7.5 MB
- Language: C++
