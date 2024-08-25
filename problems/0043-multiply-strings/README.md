# Multiply Strings

**Difficulty:** Medium
**Tags:** string, math, simulation, array

## Problem

Given two non-negative integers represented as strings (each up to 200 digits long), compute their product and return it as a string. Direct conversion to integer types or use of big-integer libraries is prohibited, requiring manual digit-by-digit multiplication.

## Approach

The solution simulates grade-school multiplication by processing digits in reverse order. It allocates a result array of size `m + n` (where m and n are the lengths of the input strings) to hold intermediate digit products. Both input strings are reversed to simplify index arithmetic.

For each pair of digits at positions `i1` and `i2`, the product is computed and added to `res[i1 + i2]`. This position corresponds to where that partial product contributes in the final result. Immediately after adding each digit product, the code propagates any carry by adding `res[i1 + i2] / 10` to the next position and taking the remainder modulo 10.

After all digit pairs are processed, the result array is converted back to a string. Leading zeros are skipped by starting from the most significant end and advancing past any zeros. The remaining digits are then appended to a stringstream in reverse order to produce the final answer.

## Complexity

- **Time:** O(m * n)
- **Space:** O(m + n)

## Stats

- Submitted: 2024-08-25 03:48 UTC
- Runtime: 0 ms
- Memory: 8.9 MB
- Language: C++
