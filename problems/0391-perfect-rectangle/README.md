# Perfect Rectangle

**Difficulty:** Hard
**Tags:** geometry, hash-table, math, coordinate-compression

## Problem

Given a collection of axis-aligned rectangles (each defined by bottom-left and top-right coordinates), determine whether they perfectly tile a larger rectangle with no gaps or overlaps. The rectangles can number up to 20,000, and coordinates range from -10^5 to 10^5.

## Approach

The solution tracks corner points using a map to count how many times each coordinate pair appears as a corner across all rectangles. It simultaneously computes the bounding box (min/max x and y coordinates) and accumulates the total area of all input rectangles.

For a perfect rectangular cover, the four corners of the bounding box must each appear exactly once, while all interior corners must appear an even number of times (2 or 4). This is because interior points are shared by adjacent rectangles: a point shared by two rectangles along an edge appears twice, while a point where four rectangles meet appears four times. Any odd count indicates a gap or protrusion.

The solution iterates through all corner occurrences, verifying that the bounding box corners appear exactly once and all other corners have even counts (2 or 4). Finally, it confirms the sum of individual rectangle areas equals the bounding box area, which catches overlaps that might otherwise pass the corner-counting test.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2026-01-16 21:51 UTC
- Runtime: 48 ms
- Memory: 38.1 MB
- Language: C++
