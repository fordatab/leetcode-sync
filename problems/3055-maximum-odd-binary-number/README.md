# Maximum Odd Binary Number

**Difficulty:** Easy
**Tags:** string, greedy, counting, bit-manipulation

## Problem

Given a binary string with at least one '1', rearrange the bits to form the maximum possible odd binary number. A binary number is odd if its least significant bit (rightmost position) is '1'. The string length is at most 100, and leading zeros are allowed in the result.

## Approach

The solution counts the number of '1's and '0's in the input string. To maximize the binary number while ensuring it remains odd, the algorithm places all '1's except one at the front (most significant positions), followed by all '0's, and finally places the reserved '1' at the end to guarantee the number is odd. This greedy approach works because:

- Placing '1's at the front maximizes the value
- Keeping exactly one '1' at the end ensures oddness
- All '0's go in the middle positions

The implementation uses two counters to track digits, then builds the result string by appending `one-1` ones, then all zeros, then the final '1'.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-15 02:41 UTC
- Runtime: 4 ms
- Memory: 8.8 MB
- Language: C++
