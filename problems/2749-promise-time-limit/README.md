# Promise Time Limit

**Difficulty:** Medium
**Tags:** promises, async-await, higher-order-function, race-condition, timeout

## Problem

Given an async function and a time limit in milliseconds, create a wrapper that returns a time-limited version of that function. The wrapper should resolve with the original function's result if it completes within the time limit, or reject with "Time Limit Exceeded" if the time limit is reached first. The function can accept 0-10 arguments and the time limit ranges from 0 to 1000 milliseconds.

## Approach

The solution wraps the original async function in a higher-order function that returns a new async function. When invoked, this wrapper creates two competing promises: one from calling the original function with the provided arguments, and a timeout promise that rejects after `t` milliseconds with the string "Time Limit Exceeded".

The key technique is `Promise.race()`, which resolves or rejects with the first promise to settle. If the original function completes before the timeout, its result is returned. If the timeout fires first, the race rejects with the timeout error message.

This approach leverages JavaScript's promise concurrency primitives to implement the timeout behavior without manually tracking promise state or cleanup. The spread operator `...args` allows the wrapper to forward any number of arguments to the original function.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-10 21:40 UTC
- Runtime: 67 ms
- Memory: 49.4 MB
- Language: JavaScript
