# Single Number II

**Difficulty:** Medium
**Tags:** bit-manipulation, array, counting

## Problem

Given an array of integers where every element appears exactly three times except for one element that appears only once, find and return the unique element. The solution must run in linear time and use constant extra space, with array lengths up to 30,000 and values in the full 32-bit signed integer range.

## Approach

This solution uses bit manipulation with two variables (`o` and `t`) to track the count of each bit position across all numbers modulo 3. The variable `o` (ones) tracks bits that have appeared once, while `t` (twos) tracks bits that have appeared twice. For each number in the array:

- First, update `o` by XORing with the current number and masking out any bits already in `t` (since a bit appearing three times should reset to zero)
- Then, update `t` by XORing with the current number and masking out any bits in the updated `o` (to properly track the two-count state)

When a bit appears three times, it gets cleared from both `o` and `t`. Since all repeating numbers appear exactly three times, their bits cancel out completely, leaving only the bits of the single unique number in `o`, which is returned as the answer.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-08 05:42 UTC
- Runtime: 8 ms
- Memory: 12.1 MB
- Language: C++
