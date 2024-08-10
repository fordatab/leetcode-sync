# Create Hello World Function

**Difficulty:** Easy
**Tags:** closure, function, higher-order-function

## Problem

The task is to implement a factory function that returns another function. The returned function must always return the string "Hello World", regardless of what arguments (if any) are passed to it. The input constraints specify that between 0 and 10 arguments may be passed when calling the returned function.

## Approach

The solution uses a closure to create a function factory. The `createHelloWorld` function defines a constant `greeting` containing the string "Hello World", then returns an anonymous function that captures this variable in its closure. When the returned function is invoked (regardless of arguments), it simply returns the captured `greeting` constant. This approach leverages JavaScript's lexical scoping, where the inner function maintains access to variables from its outer function's scope even after the outer function has completed execution.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-10 21:49 UTC
- Runtime: 54 ms
- Memory: 48.2 MB
- Language: JavaScript
