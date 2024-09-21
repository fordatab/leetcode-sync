# Calculate Money in Leetcode Bank

**Difficulty:** Easy
**Tags:** math, arithmetic-progression, simulation

## Problem

Given n days, calculate the total money saved where deposits start at $1 on the first Monday and increase by $1 each day within a week (Monday through Sunday). Each subsequent Monday's deposit is $1 more than the previous Monday's starting amount. The constraint is 1 ≤ n ≤ 1000.

## Approach

The solution decomposes the problem into complete weeks and remaining days. For complete weeks, it calculates the sum using an arithmetic formula: each week contributes a base amount of 28 (sum of 1-7), and each subsequent week adds 7 more than the previous week. The formula `w * 28 + 7 * w * (w - 1) / 2` accounts for w complete weeks where the second term represents the incremental increase across weeks.

For the remaining partial week (if any), it simulates day-by-day deposits starting from `w + 1` (the Monday amount for the incomplete week) and incrementing by 1 for each remaining day. This handles the leftover days that don't form a complete week.

The arithmetic approach avoids simulating all n days individually, making it efficient for the given constraints.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-21 06:26 UTC
- Runtime: 0 ms
- Memory: 7.6 MB
- Language: C++
