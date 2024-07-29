# Reformat Phone Number

**Difficulty:** Easy
**Tags:** string, string-manipulation, simulation

## Problem

Given a phone number string containing digits, spaces, and dashes, remove all non-digit characters and reformat the digits by grouping them into blocks of 3 from left to right. When 4 or fewer digits remain, apply special rules: 2 digits form one block, 3 digits form one block, and 4 digits form two blocks of 2. Separate all blocks with dashes, ensuring no single-digit blocks are created.

## Approach

The solution first filters out all non-digit characters while simultaneously building the output string with dashes inserted every 3 digits. As it iterates through the input, it counts digits (variable `i`) and inserts a dash before every third digit (when `i % 3 == 0` and `i` is non-zero).

After processing all digits, if the total count modulo 3 equals 1, this means the last block would be a single digit (violating the problem constraints). To fix this, the code swaps the dash and the digit at positions -2 and -3 from the end. This effectively converts a "3-1" grouping into a "2-2" grouping by moving the dash one position left.

For example, if the preliminary output is "123-4", swapping positions -2 and -3 transforms it to "12-34", which properly creates two blocks of 2 digits each.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-29 06:49 UTC
- Runtime: 3 ms
- Memory: 7.8 MB
- Language: C++
