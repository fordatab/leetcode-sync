# Calculate Amount Paid in Taxes

**Difficulty:** Easy
**Tags:** array, simulation, greedy, math

## Problem

Given a progressive tax system represented as sorted brackets (each with an upper bound and tax rate) and a total income, calculate the total tax owed. Each bracket taxes only the income that falls within its range, not the entire income. The brackets array has up to 100 elements, and both upper bounds and income are capped at 1000.

## Approach

The solution iterates through tax brackets sequentially, processing income from lowest to highest bracket. For each bracket, it determines how much income falls within that bracket by taking the minimum of remaining income and the bracket's range (current upper bound minus previous upper bound). It then applies that bracket's tax rate to the income portion, accumulates the tax, and reduces the remaining income by the amount just processed. The iteration continues until all income has been taxed. A `prev` variable tracks the upper bound of the previous bracket to correctly calculate each bracket's width.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2025-10-02 01:44 UTC
- Runtime: 23 ms
- Memory: 17.7 MB
- Language: C++
