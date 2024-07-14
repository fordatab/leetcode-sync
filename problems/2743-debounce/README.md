# Debounce

**Difficulty:** Medium
**Tags:** closure, timer, higher-order-function

## Problem

Given a function and a delay time in milliseconds, create a debounced version that postpones execution by the specified delay. If the debounced function is called again before the delay expires, the previous pending execution is cancelled and a new delay window starts. The debounced function should accept and forward all arguments to the original function.

## Approach

The solution uses a closure to maintain a `timer` variable that tracks the current pending timeout. Each time the returned debounced function is called, it first cancels any existing timeout using `clearTimeout(timer)`, then schedules a new execution of the original function after `t` milliseconds using `setTimeout`. The rest parameter syntax `...args` captures all arguments passed to the debounced function, and these are forwarded to the original function when the timeout fires. This ensures only the most recent call within any sliding window executes, with all earlier calls in that window being cancelled.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-14 06:56 UTC
- Runtime: 63 ms
- Memory: 49.5 MB
- Language: JavaScript
