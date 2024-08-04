# Fizz Buzz

**Difficulty:** Easy
**Tags:** array, string, math, simulation

## Problem

Given a positive integer n, construct an array of strings from 1 to n where each position contains "FizzBuzz" if the number is divisible by both 3 and 5, "Fizz" if divisible only by 3, "Buzz" if divisible only by 5, or the number itself as a string otherwise. The constraint is that n can range from 1 to 10,000.

## Approach

The solution iterates through integers from 1 to n inclusive, building the result array one element at a time. For each number i, it uses a chained ternary operator to determine the appropriate string value.

The key optimization is checking divisibility by 15 first (since 15 = 3 × 5), which handles the "FizzBuzz" case. Then it checks divisibility by 5 for "Buzz", followed by divisibility by 3 for "Fizz". If none of these conditions match, it converts the integer to a string using `to_string()`.

Each computed string is appended to the result vector using `push_back()`, and the completed vector is returned after the loop finishes.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-04 01:58 UTC
- Runtime: 0 ms
- Memory: 11.6 MB
- Language: C++
