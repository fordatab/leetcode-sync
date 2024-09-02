# Remove Trailing Zeros From a String

**Difficulty:** Easy
**Tags:** string, string-manipulation, iteration

## Problem

Given a string representing a positive integer, remove all trailing zeros (zeros at the end of the string) and return the resulting string. The input string has between 1 and 1000 characters, contains only digits, and has no leading zeros.

## Approach

The solution iteratively removes characters from the end of the string while the last character is '0'. It uses a while loop that checks if the back of the string is a zero character using `num.back()`, and if so, removes it with `num.pop_back()`. This continues until either all trailing zeros are removed or the string has no more zeros at the end. The modified string is then returned.

## Complexity

- **Time:** O(k)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-02 07:00 UTC
- Runtime: 6 ms
- Memory: 10.8 MB
- Language: C++
