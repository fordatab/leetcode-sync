# Summary Ranges

**Difficulty:** Easy
**Tags:** array, two-pointers, string-formatting

## Problem

Given a sorted array of unique integers, group consecutive integers into ranges and return them as formatted strings. Each range should be represented as "a->b" when it contains multiple consecutive numbers, or just "a" when it contains a single number. The array can have up to 20 elements with values in the 32-bit integer range.

## Approach

The solution uses a two-pointer technique with a nested loop structure. The outer loop variable `x` iterates through the array, while the inner `while` loop extends `x` forward as long as consecutive integers are found (checking if `nums[x] + 1 == nums[x+1]`). The variable `i` marks the start of each range. When the inner loop terminates, the code checks if `i == x` (single element range) to format the output as just the number, otherwise it formats as "start->end". The outer loop processes elements up to `nums.size()-1` to avoid out-of-bounds access in the consecutive check. After the loop, there's a special case to handle the last element if it wasn't part of a range that extended to the end.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-18 08:29 UTC
- Runtime: 3 ms
- Memory: 8.6 MB
- Language: C++
