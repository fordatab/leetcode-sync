# Missing Number

**Difficulty:** Easy
**Tags:** hash-table, array, set

## Problem

Given an array of n distinct integers where each value falls in the range [0, n], find the single missing integer from that range. The array contains exactly n elements, so one value between 0 and n inclusive is absent. All values in the array are unique, and n can be up to 10,000.

## Approach

The solution uses a hash set to store all numbers present in the input array. It constructs an `unordered_set` from the input vector for O(1) average-case lookup time. Then it iterates through all possible values from 0 to n (inclusive), checking each one against the set. The first value that is not found in the set is the missing number, which is immediately returned. This approach trades space for simplicity: instead of using mathematical properties like XOR or sum formulas, it explicitly tracks which numbers are present and searches linearly for the gap.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-18 02:57 UTC
- Runtime: 31 ms
- Memory: 28 MB
- Language: C++
