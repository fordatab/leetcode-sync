# Counter II

**Difficulty:** Easy
**Tags:** closure, object, function, state-management

## Problem

Design a counter factory function that accepts an initial integer value and returns an object with three methods: increment (increases the counter by 1 and returns the new value), decrement (decreases the counter by 1 and returns the new value), and reset (restores the counter to its initial value and returns it). The initial value ranges from -1000 to 1000, and up to 1000 method calls may be made on any counter instance.

## Approach

The solution uses closure to maintain state across method calls. The `createCounter` function stores the initial value in the `init` parameter and creates a mutable `presentCount` variable initialized to that value. It returns an object literal with three arrow functions that form a closure over `presentCount`. The `increment` method uses the prefix increment operator (`++presentCount`) to add 1 before returning, `decrement` uses prefix decrement (`--presentCount`) to subtract 1 before returning, and `reset` reassigns `presentCount` to the captured `init` value. Each counter instance maintains its own independent state through its own closure scope.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-10 21:47 UTC
- Runtime: 62 ms
- Memory: 52.1 MB
- Language: JavaScript
