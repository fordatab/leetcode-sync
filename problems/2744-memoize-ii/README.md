# Memoize II

**Difficulty:** Hard
**Tags:** hash-table, memoization, nested-map, function-composition

## Problem

Create a memoization wrapper for any function that caches results based on argument identity. Arguments are considered identical only if they share the same reference (using strict equality ===), meaning different object instances with the same content are treated as distinct keys. The memoized function must avoid re-executing when called with previously seen argument combinations, returning the cached result instead.

## Approach

The solution builds a nested Map structure where each argument in the parameter list corresponds to a level in the tree. For a function call with arguments [a, b, c], the cache structure becomes Map(a -> Map(b -> Map(c -> result))). 

When the memoized function is invoked, it iterates through each parameter sequentially. For each parameter, it checks if a Map entry exists at the current cache level; if not, it creates a new Map and stores it. The algorithm then descends into that nested Map for the next parameter.

After processing all parameters, a special Symbol (RES) is used as the final key to store and retrieve the actual function result. This Symbol ensures the result key never conflicts with any parameter value. If the result is found in the cache, it's returned immediately; otherwise, the original function is called, the result is cached at the deepest level, and then returned.

## Complexity

- **Time:** O(n)
- **Space:** O(m * n)

## Stats

- Submitted: 2024-08-10 21:42 UTC
- Runtime: 364 ms
- Memory: 113.2 MB
- Language: JavaScript
