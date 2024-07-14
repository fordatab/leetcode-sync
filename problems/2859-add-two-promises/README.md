# Add Two Promises

**Difficulty:** Easy
**Tags:** promises, async-await, asynchronous-programming

## Problem

Given two promises that will each resolve to a numeric value, create and return a new promise that resolves to the sum of those two numbers. The promises may resolve at different times, but the result should be their combined total regardless of timing.

## Approach

The solution uses an async function to handle promise resolution. It employs `Promise.all()` to wait for both input promises to resolve concurrently, which returns an array of their resolved values. Using destructuring assignment, the two numeric values are extracted into separate variables. The function then returns the sum of these values, which is automatically wrapped in a resolved promise due to the async function's behavior (async functions always return promises).

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-14 06:56 UTC
- Runtime: 62 ms
- Memory: 49.1 MB
- Language: JavaScript
