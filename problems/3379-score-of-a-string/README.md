# Score of a String

**Difficulty:** Easy
**Tags:** string, array, simulation

## Problem

Given a string of lowercase English letters (length 2-100), calculate its score by summing the absolute differences between ASCII values of all adjacent character pairs. For example, in "hello", you compute |ASCII('h')-ASCII('e')| + |ASCII('e')-ASCII('l')| + |ASCII('l')-ASCII('l')| + |ASCII('l')-ASCII('o')|.

## Approach

The solution uses a simple linear scan through the string with a single loop. It initializes an accumulator variable `t` to zero, then iterates from index 0 to `s.size()-2`. At each position `x`, it computes the absolute difference between the ASCII values of characters at positions `x` and `x+1` using `abs(s[x]-s[x+1])`, adding this value to the running total. The character-to-ASCII conversion happens implicitly when subtracting `char` values in C++. After processing all adjacent pairs, the function returns the accumulated sum.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-11 07:56 UTC
- Runtime: 5 ms
- Memory: 7.8 MB
- Language: C++
