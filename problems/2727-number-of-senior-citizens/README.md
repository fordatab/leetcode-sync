# Number of Senior Citizens

**Difficulty:** Easy
**Tags:** string, array, iteration

## Problem

Given an array of fixed-length strings where each string encodes passenger information (phone number, gender, age, and seat), count how many passengers have an age strictly greater than 60. The age is encoded in characters at indices 11 and 12 of each 15-character string, forming a two-digit number.

## Approach

The solution iterates through each passenger detail string and examines the age digits at positions 11 and 12. It uses a nested conditional approach: first checking if the tens digit (index 11) is at least '6'. If the tens digit is exactly '6', it additionally checks whether the ones digit (index 12) is greater than '0' to ensure the age is strictly more than 60 (i.e., 61-69). If the tens digit is '7' or higher, the passenger is automatically counted since they're at least 70 years old. The solution maintains a counter that increments for each senior citizen found and returns this count.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-01 01:04 UTC
- Runtime: 6 ms
- Memory: 17.6 MB
- Language: C++
