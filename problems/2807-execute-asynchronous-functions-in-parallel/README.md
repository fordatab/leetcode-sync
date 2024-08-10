# Execute Asynchronous Functions in Parallel

**Difficulty:** Medium
**Tags:** promises, asynchronous, concurrency, array

## Problem

Given an array of asynchronous functions that each return a promise, implement a function that executes all of them in parallel and returns a new promise. This promise should resolve with an array of all resolved values (in the original order) when all input promises succeed, or reject immediately with the first rejection reason if any promise fails. The solution must not use the built-in Promise.all method. The input array has 1-10 functions.

## Approach

The solution creates a new Promise and manually tracks the completion of all input promises. It pre-allocates a results array of the same length as the input functions array to preserve ordering. Using `forEach`, it immediately invokes each function and attaches `.then()` and `.catch()` handlers to the returned promise.

Each successful resolution stores its value at the corresponding index in the results array and increments a counter. When the counter equals the total number of functions, all promises have resolved, so it calls `resolve(results)` with the complete array.

If any promise rejects, its `.catch()` handler immediately calls `reject(reason)`, causing the outer promise to reject with that error. Because rejection happens immediately upon the first failure, this mimics the fail-fast behavior of Promise.all.

By invoking all functions via `forEach` before any of them complete, all promises execute concurrently rather than sequentially. The index-based storage ensures the output array maintains the same order as the input regardless of completion timing.

## Complexity

- **Time:** O(1)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-10 21:51 UTC
- Runtime: 67 ms
- Memory: 49.4 MB
- Language: JavaScript
