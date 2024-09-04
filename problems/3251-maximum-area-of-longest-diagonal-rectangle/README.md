# Maximum Area of Longest Diagonal Rectangle

**Difficulty:** Easy
**Tags:** array, iteration, geometry, greedy

## Problem

Given a list of rectangles where each rectangle is represented by its length and width, find the area of the rectangle with the longest diagonal. If multiple rectangles share the longest diagonal length, return the area of the one with the maximum area. The input contains up to 100 rectangles with dimensions ranging from 1 to 100.

## Approach

The solution iterates through all rectangles once, tracking two values: the squared diagonal length of the current maximum and the corresponding area.

For each rectangle, it calculates the squared diagonal (length² + width²) to avoid floating-point arithmetic, since comparing squared values preserves the same ordering as comparing the actual diagonal lengths.

When a rectangle with a strictly longer diagonal is found, both the maximum squared diagonal and the best area are updated. When a rectangle with an equal diagonal is encountered, only the area is updated if it's larger than the current best.

The algorithm uses the Pythagorean theorem implicitly (diagonal² = length² + width²) and returns the area (length × width) of the rectangle that satisfies the criteria.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-04 23:17 UTC
- Runtime: 11 ms
- Memory: 29.5 MB
- Language: C++
