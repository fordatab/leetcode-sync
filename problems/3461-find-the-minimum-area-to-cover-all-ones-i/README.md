# Find the Minimum Area to Cover All Ones I

**Difficulty:** Medium
**Tags:** matrix, array, bounding-box, simulation

## Problem

Given a 2D binary grid containing 0s and 1s, find the smallest rectangle (with sides parallel to the grid axes) that contains all the 1s in the grid. The grid dimensions can be up to 1000×1000, and at least one 1 is guaranteed to exist. Return the area of this minimal bounding rectangle.

## Approach

The solution performs a single pass through the entire grid to track the extreme positions of all 1s. It maintains four variables: the minimum and maximum row indices (`min_i`, `max_i`) and the minimum and maximum column indices (`min_j`, `max_j`) where 1s appear.

For each cell containing a 1, the code updates these boundary variables using `min` and `max` operations. After scanning the complete grid, the bounding rectangle is defined by these extremes.

The area is computed as the product of the rectangle's height and width: `(max_i - min_i + 1)` gives the number of rows spanned, and `(max_j - min_j + 1)` gives the number of columns spanned. The `+1` accounts for inclusive boundaries (a rectangle from row 0 to row 2 spans 3 rows, not 2).

## Complexity

- **Time:** O(m * n)
- **Space:** O(1)

## Stats

- Submitted: 2025-08-22 01:24 UTC
- Runtime: 257 ms
- Memory: 133.6 MB
- Language: C++
