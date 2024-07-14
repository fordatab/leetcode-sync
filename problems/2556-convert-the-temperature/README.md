# Convert the Temperature

**Difficulty:** Easy
**Tags:** math, array

## Problem

Given a temperature in Celsius as a non-negative floating point number (rounded to two decimal places, ranging from 0 to 1000), convert it to both Kelvin and Fahrenheit. Return the results as a two-element array where the first element is the Kelvin value and the second is the Fahrenheit value. Answers within 10^-5 of the actual value are acceptable.

## Approach

The solution directly applies the temperature conversion formulas in a single return statement. It uses C++ vector initialization syntax to construct and return a vector containing two elements.

For Kelvin conversion, it adds 273.15 to the input Celsius value. For Fahrenheit conversion, it multiplies the Celsius value by 1.80 and adds 32. Both calculations are performed inline within the vector initializer list.

This is a straightforward mathematical transformation with no intermediate variables or loops needed. The compiler handles the vector construction and the values are computed in a single pass.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-14 06:17 UTC
- Runtime: 0 ms
- Memory: 7.9 MB
- Language: C++
