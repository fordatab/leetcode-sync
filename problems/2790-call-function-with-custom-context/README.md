# Call Function with Custom Context

**Difficulty:** Medium
**Tags:** javascript, function-prototype, this-binding, polyfill

## Problem

Implement a polyfill for JavaScript's Function.call() method that binds a custom 'this' context to any function. The method should accept an object as the first parameter (which becomes the 'this' context) and any number of additional arguments to pass to the function. The constraint is that the built-in Function.call method cannot be used, and the context object is guaranteed to be a non-null object.

## Approach

The solution attaches a `callPolyfill` method to `Function.prototype`, making it available on all functions. When invoked:

1. It saves a reference to the original function (`this` in the context of `callPolyfill` is the function being called)
2. Temporarily attaches the function to the provided context object as a non-enumerable property named `__fn__` using `Object.defineProperty` (non-enumerable ensures it won't appear in object iterations)
3. Invokes the function through the context object (`context.__fn__(...args)`), which naturally sets `this` to `context` due to method invocation semantics
4. Cleans up by deleting the temporary property from the context object
5. Returns the result of the function call, explicitly returning `undefined` if the result is undefined

The key insight is that when a function is called as a method of an object (e.g., `obj.method()`), JavaScript automatically sets `this` to that object, allowing us to control the context without using the built-in `call` method.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-10 21:50 UTC
- Runtime: 50 ms
- Memory: 48.7 MB
- Language: JavaScript
