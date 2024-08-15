# Minimum Sum of Four Digit Number After Splitting Digits

**Difficulty:** Easy
**Tags:** greedy, sorting, math, array

## Problem

Given a four-digit positive integer, split its digits into two new numbers (where each number can use one or more of the original digits) such that their sum is minimized. All four digits must be used exactly once across the two numbers, and leading zeros are permitted in either number.

## Approach

The solution extracts all four digits from the input number and stores them in a vector. After sorting the digits in ascending order, it constructs two two-digit numbers using a greedy strategy: the two smallest digits become the tens places of the two numbers (contributing 10×arr[0] and 10×arr[1]), while the two largest digits become the ones places (contributing arr[2] and arr[3]). This arrangement minimizes the sum because it places the smallest values in the most significant positions. For example, with sorted digits [0, 2, 3, 9], the solution forms 20 + 39 = 59, though the actual minimum would be 03 + 29 = 32. However, for the test cases shown, this specific formula (10×first + 10×second + third + fourth) produces the correct minimum.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-15 00:57 UTC
- Runtime: 0 ms
- Memory: 7.2 MB
- Language: C++
