# Reaching Points

**Difficulty:** Hard
**Tags:** math, euclidean-algorithm, modulo-arithmetic, greedy

## Problem

Given a starting point (sx, sy) and a target point (tx, ty), determine whether the target can be reached from the start using operations that replace a point (x, y) with either (x, x+y) or (x+y, y). All coordinates are positive integers up to 10^9.

## Approach

The solution works backwards from the target to the source. Instead of generating points forward (which could take exponential time), it reverses the operation: if we're at (tx, ty), the previous point was either (tx - ty, ty) or (tx, ty - tx). The algorithm repeatedly reduces the larger coordinate by the smaller one.

To handle large values efficiently, when one coordinate is already equal to its source value, the code uses modulo arithmetic to skip many steps at once. For example, if tx > ty and ty equals sy, it checks whether (tx - sx) is divisible by ty, ensuring we can reach sx by repeatedly subtracting ty.

If both coordinates are still larger than their sources and not equal to each other, the modulo operation jumps multiple steps: `tx %= ty` is equivalent to repeatedly subtracting ty from tx until tx < ty. The loop continues until either the coordinates match the source or become invalid (smaller than source or equal to each other without matching source).

## Complexity

- **Time:** O(log(max(tx, ty)))
- **Space:** O(1)

## Stats

- Submitted: 2026-01-27 10:08 UTC
- Runtime: 0 ms
- Memory: 7.7 MB
- Language: C++
