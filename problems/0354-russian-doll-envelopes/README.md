# Russian Doll Envelopes

**Difficulty:** Hard
**Tags:** sorting, binary-search, dynamic-programming, longest-increasing-subsequence, greedy

## Problem

Given an array of envelopes where each envelope has a width and height, find the maximum number of envelopes that can be nested inside one another. An envelope can only fit inside another if both its dimensions are strictly smaller. The input can contain up to 100,000 envelopes with dimensions up to 100,000 each.

## Approach

The solution transforms the 2D nesting problem into a 1D longest increasing subsequence (LIS) problem. First, it sorts the envelopes by width in ascending order, but for envelopes with equal widths, it sorts heights in descending order. This clever sorting ensures that among envelopes with the same width, only one can be selected in the final sequence.

After sorting, the problem reduces to finding the LIS of the heights. The code uses binary search with `lower_bound` to efficiently maintain a vector `lis` that represents the smallest tail element for each possible subsequence length. For each envelope's height, it either extends the sequence (if the height is larger than all existing values) or replaces an existing value to keep the subsequence optimally positioned for future extensions.

The descending height order for equal widths is critical: it prevents multiple envelopes with identical widths from being counted in the same nesting sequence, since a strictly increasing subsequence cannot include two equal or decreasing values that appear consecutively.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2026-01-12 05:22 UTC
- Runtime: 101 ms
- Memory: 92 MB
- Language: C++
