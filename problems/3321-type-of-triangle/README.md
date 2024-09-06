# Type of Triangle

**Difficulty:** Easy
**Tags:** geometry, array, math, conditional-logic

## Problem

Given an array of exactly three positive integers representing potential triangle sides, determine whether they can form a valid triangle and classify it as equilateral (all sides equal), isosceles (exactly two sides equal), or scalene (all sides different). The triangle inequality theorem must be satisfied: the sum of any two sides must be strictly greater than the third side.

## Approach

The solution uses a straightforward classification approach. First, it validates the triangle inequality by checking if any single side is greater than or equal to the sum of the other two sides — if so, it returns "none" since no valid triangle can be formed. Once validity is confirmed, it categorizes the triangle by comparing the three side lengths: if all three are equal, it's equilateral; if any two are equal (but not all three), it's isosceles; otherwise, all sides differ and it's scalene. The checks are performed in order of specificity to ensure correct classification.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-06 09:05 UTC
- Runtime: 0 ms
- Memory: 22.6 MB
- Language: C++
