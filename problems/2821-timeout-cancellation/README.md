# Timeout Cancellation

**Difficulty:** Easy
**Tags:** closure, timer, higher-order-function, asynchronous

## Problem

The task is to create a function that schedules another function to execute after a specified delay, but returns a cancellation function that can prevent the scheduled execution if called before the delay expires. The function must accept a target function, its arguments, and a timeout value, then return a cancel function that clears the scheduled timeout when invoked.

## Approach

The solution uses JavaScript's `setTimeout` to schedule the provided function `fn` to execute after `t` milliseconds with the spread arguments. It stores the timeout identifier in a `timer` variable. The returned `cancelFn` closure captures this `timer` reference and calls `clearTimeout(timer)` when invoked, which cancels the pending execution. If `cancelFn` is called before the timeout expires, the function never runs; otherwise, it executes as scheduled.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-19 03:28 UTC
- Runtime: 68 ms
- Memory: 49.7 MB
- Language: JavaScript
