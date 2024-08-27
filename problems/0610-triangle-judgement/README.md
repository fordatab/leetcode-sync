# Triangle Judgement

**Difficulty:** Easy
**Tags:** sql, conditional-logic, geometry, triangle-inequality

## Problem

Given a table with three integer columns (x, y, z) representing the lengths of three line segments, determine whether each row's segments can form a valid triangle. The output should include all original columns plus a new column indicating 'Yes' or 'No' for triangle validity.

## Approach

The solution applies the triangle inequality theorem directly in SQL. For three sides to form a triangle, the sum of any two sides must be strictly greater than the third side. The query uses a conditional `IF` statement to check all three conditions: x+y>z, y+z>x, and z+x>y. If all three inequalities hold true, the result is 'Yes'; otherwise, it's 'No'. This value is returned as a new column named 'triangle' alongside all the original columns from the Triangle table.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-27 10:59 UTC
- Runtime: 245 ms
- Memory: 0B
- Language: MySQL
