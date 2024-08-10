# Memoize

**Difficulty:** Medium
**Tags:** memoization, closure, hash-table, higher-order-function

## Problem

Create a memoization wrapper that caches function results based on input arguments. The wrapper must return cached values when called with previously seen arguments, avoiding redundant computation. The solution must handle functions with varying argument counts (one or two parameters) and track how many times the original function is actually invoked versus serving cached results.

## Approach

The solution implements a closure-based memoization pattern. It creates a `cache` object outside the returned function to persist across calls. When the memoized function is invoked, it serializes the arguments array into a JSON string to use as a cache key. This string-based key allows matching argument lists regardless of their length.

Before calling the original function, it checks if the serialized key exists in the cache using the `in` operator. If found, it immediately returns the cached value without executing `fn`. Otherwise, it calls the original function using `apply` to preserve the correct `this` context and spread the arguments, stores the result in the cache under the serialized key, and returns the result.

The `JSON.stringify(args)` approach handles both single-argument functions like `fib` and `factorial`, and two-argument functions like `sum`. Because the serialization preserves argument order, `(2, 3)` and `(3, 2)` produce different keys and are cached separately, which satisfies the requirement that argument order matters.

## Complexity

- **Time:** O(1)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-10 07:09 UTC
- Runtime: 283 ms
- Memory: 90.2 MB
- Language: JavaScript
