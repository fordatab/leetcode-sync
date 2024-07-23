# Allow One Function Call

**Difficulty:** Easy
**Tags:** closure, function-wrapper, higher-order-function, memoization

## Problem

Create a wrapper function that ensures a given function can only be executed once. The first invocation should call the original function and return its result, while all subsequent invocations should return undefined without calling the original function. The wrapper must work with any function and preserve its arguments.

## Approach

The solution uses closure to maintain state across multiple invocations. A boolean flag `hasBeenCalled` tracks whether the wrapped function has been executed, and a `result` variable stores the return value from the first call.

The wrapper returns a new function that accepts any number of arguments via the rest parameter syntax (`...args`). On the first invocation, it checks the flag, calls the original function with the spread arguments, stores both the result and updates the flag to true, then returns the result.

On subsequent invocations, the flag is already true, so the function immediately returns undefined without calling the original function. The closure preserves these variables between calls, ensuring the state persists across the lifetime of the wrapped function.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-23 08:59 UTC
- Runtime: 49 ms
- Memory: 49 MB
- Language: JavaScript
