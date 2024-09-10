# Candy

**Difficulty:** Hard
**Tags:** greedy, array, two-pointer, sliding-window

## Problem

Given n children in a line with integer ratings, distribute candies such that each child gets at least one candy and any child with a higher rating than a neighbor receives more candies than that neighbor. The goal is to find the minimum total number of candies needed. The array can have up to 20,000 children with ratings from 0 to 20,000.

## Approach

The solution uses a single-pass greedy approach that treats the ratings array as a series of peaks and valleys. It starts by allocating one candy to each child as a baseline.

When scanning left-to-right, it identifies three patterns:
- **Plateaus** (equal consecutive ratings): skip ahead since no additional candies are needed beyond the baseline
- **Increasing slopes**: incrementally add candies (1, 2, 3, ...) as the rating increases, tracking the peak height
- **Decreasing slopes**: similarly add candies for the descending sequence, tracking the valley depth

The key insight is the overlap handling: when transitioning from an ascending to descending slope, the pivot child is counted in both sequences. To avoid double-counting, the algorithm subtracts the minimum of the peak and valley heights, keeping only the larger requirement for that position. This ensures the pivot child has enough candies to satisfy both the ascending constraint from the left and descending constraint from the right.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-10 05:15 UTC
- Runtime: 4 ms
- Memory: 19.8 MB
- Language: C++
