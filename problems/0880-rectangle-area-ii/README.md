# Rectangle Area II

**Difficulty:** Hard
**Tags:** coordinate-compression, sweep-line, line-sweep, interval-merging, computational-geometry

## Problem

Given up to 200 axis-aligned rectangles on a 2D plane (with coordinates up to 10^9), compute the total area covered by their union, counting overlapping regions only once. The result must be returned modulo 10^9 + 7.

## Approach

The solution uses a **coordinate compression** and **sweep line** technique. First, it collects all unique x-coordinates from the rectangle edges and sorts them to define vertical strips. For each consecutive pair of x-coordinates forming a strip [x1, x2), it identifies which rectangles span that strip horizontally. Within each strip, the code projects the active rectangles onto the y-axis, creating a set of y-intervals. These intervals are then sorted and merged to eliminate overlaps, yielding the total vertical coverage in that strip. The area contribution of each strip is the product of its width (x2 - x1) and the merged y-coverage. All contributions are summed with modular arithmetic to produce the final answer.

## Complexity

- **Time:** O(n^2 log n)
- **Space:** O(n)

## Stats

- Submitted: 2026-02-06 05:13 UTC
- Runtime: 2 ms
- Memory: 13.1 MB
- Language: C++
