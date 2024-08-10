# Interval Cancellation

**Difficulty:** Easy
**Tags:** closures, higher-order-functions, timers, javascript

## Problem

Create a higher-order function that takes a function, arguments, and an interval time, then immediately invokes the function and schedules it to run repeatedly at the specified interval. The function must return a cancellation callback that stops the repeated execution when called. The interval time ranges from 30-100ms, and cancellation occurs between 10-500ms after the interval starts.

## Approach

The solution uses JavaScript's `setInterval` to schedule repeated function execution. It first calls the function immediately with the spread arguments (`fn(...args)`), then sets up a repeating timer that calls the same function every `t` milliseconds. The interval ID returned by `setInterval` is stored in a closure variable. The cancellation function simply calls `clearInterval` with this stored ID to stop the repeating timer. When the returned cancel function is invoked (typically via `setTimeout` in the test harness), it clears the interval and prevents further executions.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-10 21:55 UTC
- Runtime: 81 ms
- Memory: 49.2 MB
- Language: JavaScript
