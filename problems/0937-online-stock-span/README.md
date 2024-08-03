# Online Stock Span

**Difficulty:** Medium
**Tags:** stack, monotonic-stack, design

## Problem

Build a data structure that processes stock prices one at a time and returns the "span" for each new price. The span is the count of consecutive preceding days (including today) where prices were less than or equal to today's price. Prices range from 1 to 100,000, and up to 10,000 price queries will be made.

## Approach

The solution uses a monotonic decreasing stack that stores pairs of (price, span). For each new price:

- Initialize the current span to 1
- While the stack is non-empty and the top price is less than or equal to the current price, pop elements from the stack and accumulate their spans into the current span
- Push the current price and its computed span onto the stack
- Return the computed span

The key insight is that when we encounter a price P, all previous prices ≤ P can be "absorbed" into P's span. By storing the previously computed spans, we avoid recounting days. The stack maintains prices in decreasing order, so popping smaller prices efficiently finds how far back the current price dominates.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-03 04:33 UTC
- Runtime: 167 ms
- Memory: 90.3 MB
- Language: C++
