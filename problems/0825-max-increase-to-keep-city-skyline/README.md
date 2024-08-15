# Max Increase to Keep City Skyline

**Difficulty:** Medium
**Tags:** array, greedy, matrix

## Problem

Given an n×n grid representing building heights in a city, determine the maximum total increase in building heights such that the skyline (the maximum height visible from each cardinal direction) remains unchanged. The skyline from the north/south depends on column maximums, and from east/west depends on row maximums. Each building can be increased independently, but cannot exceed the constraint imposed by both its row and column skyline.

## Approach

The solution uses a greedy approach with precomputed constraints:

1. **Precompute skyline constraints**: Create two arrays `r` and `c` to store the maximum height in each row and column respectively. These represent the skyline limits from east-west and north-south directions.

2. **Calculate maximum allowed height**: For each building at position `(x, y)`, the maximum height it can reach without affecting the skyline is `min(r[x], c[y])` — it's bounded by both the row maximum (east-west view) and column maximum (north-south view).

3. **Sum total increase**: Iterate through all positions again, computing the difference between the maximum allowed height and the current height for each building. The sum of all these differences is the answer.

The key insight is that each building can be increased up to the minimum of its row and column skyline constraints, ensuring neither view is altered.

## Complexity

- **Time:** O(n²)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-15 02:37 UTC
- Runtime: 2 ms
- Memory: 12.9 MB
- Language: C++
