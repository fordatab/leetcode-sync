# To Be Or Not To Be

**Difficulty:** Easy
**Tags:** closure, object-methods, testing-utilities

## Problem

Implement a function that returns an object with two assertion methods for testing purposes. The `toBe` method should return true if two values are strictly equal (using `===`), throwing "Not Equal" otherwise. The `notToBe` method should return true if two values are strictly not equal (using `!==`), throwing "Equal" otherwise.

## Approach

The solution uses a closure to capture the initial value passed to `expect`. It returns an object with two methods:

- `toBe`: Compares the captured value with the argument using strict inequality (`!==`). If they differ, it throws an error with message "Not Equal"; otherwise returns true.
- `notToBe`: Compares the captured value with the argument using strict equality (`===`). If they match, it throws an error with message "Equal"; otherwise returns true.

Both methods leverage JavaScript's closure mechanism to maintain access to the original `val` parameter while accepting a second value (`val2`) for comparison.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-10 21:47 UTC
- Runtime: 55 ms
- Memory: 49.1 MB
- Language: JavaScript
