# Minimum Suffix Flips

**Difficulty:** Medium
**Tags:** greedy, string, simulation, bit-manipulation

## Problem

Given a binary string target of length n, start with a string s of all zeros. In each operation, you can choose an index i and flip all bits from position i to the end of the string. Determine the minimum number of such suffix-flip operations needed to transform s into target. The string length can be up to 100,000.

## Approach

The solution uses a greedy single-pass approach that simulates the state of the string as operations are applied. It maintains a `current_state` variable that tracks what value the current position should have after all previous operations. Starting with `current_state = '0'` (matching the initial all-zeros string), it iterates through each character of the target string. Whenever the target character differs from the current state, it means a flip operation is needed at this position, so the operation count increments and the current state toggles to match the target character. This works because flipping at position i affects all positions from i onward, so once we flip to match a position, all subsequent positions inherit that flipped state until another mismatch is encountered. The key insight is that we only need to count the number of transitions (changes) between consecutive positions in the target when accounting for the cumulative effect of suffix flips.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-07-17 06:54 UTC
- Runtime: 3 ms
- Memory: 12.5 MB
- Language: C++
