# Maximum 69 Number

**Difficulty:** Easy
**Tags:** string, greedy, math

## Problem

Given a positive integer (at most 10^4) composed exclusively of the digits 6 and 9, find the maximum possible value obtainable by changing at most one digit. Changing a digit means flipping a 6 to a 9 or a 9 to a 6.

## Approach

The solution converts the integer to a string and scans from left to right. Since we want to maximize the result, we should change the leftmost (most significant) 6 to a 9, as this yields the largest increase. The code iterates through each character, and upon finding the first '6', it changes it to '9' and immediately breaks. If no '6' is found (the number consists entirely of 9s), no change is made. Finally, the modified string is converted back to an integer and returned.

## Complexity

- **Time:** O(d)
- **Space:** O(d)

## Stats

- Submitted: 2024-07-24 20:29 UTC
- Runtime: 0 ms
- Memory: 7.7 MB
- Language: C++
