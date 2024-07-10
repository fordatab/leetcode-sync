# Greatest Common Divisor of Strings

**Difficulty:** Easy
**Tags:** string, math, greatest-common-divisor

## Problem

Given two strings, find the longest string that can be repeatedly concatenated to form both input strings. A string x "divides" another string s if s can be formed by concatenating x with itself one or more times. The constraints specify that both input strings have lengths between 1 and 1000 and contain only uppercase English letters.

## Approach

The solution leverages a mathematical property: if two strings share a common divisor string, then concatenating them in different orders (str1+str2 vs str2+str1) will produce the same result. First, it checks this concatenation property to quickly determine if any common divisor exists. If the concatenations differ, no common divisor is possible and an empty string is returned.

If a common divisor exists, its length must be the greatest common divisor (GCD) of the two string lengths. This is because any valid divisor string must evenly divide both lengths. The code uses the built-in GCD function on the string lengths to find this optimal length.

Finally, it extracts and returns a substring of that GCD length from the beginning of str1, which represents the largest common divisor string.

## Complexity

- **Time:** O(n + m)
- **Space:** O(n + m)

## Stats

- Submitted: 2024-07-10 06:29 UTC
- Runtime: 5 ms
- Memory: 8.6 MB
- Language: C++
