# Max Points on a Line

**Difficulty:** Hard
**Tags:** geometry, brute-force, collinearity, cross-product

## Problem

Given a collection of points on a 2D plane (each point specified by x and y coordinates), determine the maximum number of points that can be connected by a single straight line. The input contains between 1 and 300 unique points, with coordinates ranging from -10,000 to 10,000.

## Approach

The solution uses a brute-force approach with three nested loops. For every pair of points (i, j), it treats them as defining a line and then checks all other points to see if they lie on the same line.

To avoid floating-point division when calculating slopes, the code uses the cross-product formula to check collinearity: three points (i, j, k) are collinear if the slope from i to j equals the slope from i to k. This is verified by cross-multiplying: `(y_j - y_i) * (x_i - x_k) == (y_i - y_k) * (x_j - x_i)`.

For each pair of points, it initializes a count of 2 (the pair itself) and increments the count for every additional point that satisfies the collinearity condition. The maximum count across all pairs is tracked and returned as the answer.

The algorithm directly examines all possible line configurations without optimization techniques like hashing slopes, resulting in O(n³) time complexity but simple, readable code.

## Complexity

- **Time:** O(n^3)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-08 00:48 UTC
- Runtime: 107 ms
- Memory: 9.3 MB
- Language: C++
