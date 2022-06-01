# Integer to Roman

**Difficulty:** Medium
**Tags:** math, string, greedy

## Problem

Given an integer between 1 and 3999, convert it to its Roman numeral representation. The conversion must follow standard Roman numeral rules including the use of subtractive notation for values starting with 4 or 9 (like IV for 4, IX for 9, XL for 40, XC for 90, CD for 400, and CM for 900). The output should correctly handle all decimal place values from thousands down to ones.

## Approach

The solution processes each decimal place (thousands, hundreds, tens, ones) independently from highest to lowest. For each place value, it extracts the digit and applies specific conversion rules:

- **Thousands**: Simply append 'M' characters equal to the thousands digit (0-3 times)
- **Hundreds, Tens, Ones**: For each place, check if the digit is 4 or 9 (requiring subtractive forms like CD, CM, XL, XC, IV, IX). Otherwise, if the digit is 5 or greater, append the mid-value symbol (D for 500, L for 50, V for 5) and then repeat the base symbol (C, X, or I) for the remainder. If less than 5, just repeat the base symbol.

The algorithm uses a StringBuilder to accumulate symbols and String.repeat() to efficiently generate multiple copies of the same character. After processing each place value, it uses modulo to reduce the number and move to the next smaller place.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2022-06-01 14:07 UTC
- Runtime: 6 ms
- Memory: 45.4 MB
- Language: Java
