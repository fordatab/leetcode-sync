# Sleep

**Difficulty:** Easy
**Tags:** async-await, promises, javascript

## Problem

Create an asynchronous function that pauses execution for a specified number of milliseconds before resolving. The function accepts a positive integer representing milliseconds (between 1 and 1000) and should return a promise that resolves after approximately that duration.

## Approach

The solution uses JavaScript's `async/await` syntax combined with a Promise and `setTimeout`. Inside the async function, a new Promise is created that wraps `setTimeout`, passing the `resolve` callback directly as the timeout handler. When `setTimeout` fires after `millis` milliseconds, it calls `resolve()`, which fulfills the promise. The `await` keyword pauses the async function until this promise resolves, effectively creating the sleep behavior. This is a standard pattern for implementing sleep functionality in JavaScript since there's no built-in sleep method.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-23 08:57 UTC
- Runtime: 56 ms
- Memory: 48.2 MB
- Language: JavaScript
