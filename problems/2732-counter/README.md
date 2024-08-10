# Counter

**Difficulty:** Easy
**Tags:** closure, function, state-management

## Problem

Implement a factory function that takes an integer n and returns a counter function. The returned counter function should return n on its first invocation, then n+1 on the second invocation, n+2 on the third, and so on, incrementing by 1 each time it's called. The initial value n can range from -1000 to 1000, and the counter may be called up to 1000 times.

## Approach

The solution uses a closure to maintain state across function calls. The `createCounter` function takes an initial value `n` and returns an arrow function that captures `n` in its closure. Each time the returned function is invoked, it uses the post-increment operator (`n++`) which returns the current value of `n` and then increments it for the next call. This leverages JavaScript's closure mechanism where the inner function retains access to the outer function's variable even after the outer function has returned, allowing the counter to persist and update its state between invocations.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-10 07:09 UTC
- Runtime: 51 ms
- Memory: 48.9 MB
- Language: JavaScript
