# Return Length of Arguments Passed

**Difficulty:** Easy
**Tags:** rest-parameters, array, javascript

## Problem

Create a function that counts how many arguments are passed to it when called. The function can receive any number of arguments (from 0 to 100) of various types including primitives, arrays, and objects, and must return the total count.

## Approach

The solution uses JavaScript's rest parameter syntax (`...args`) to collect all arguments into an array. The rest parameter automatically gathers any number of arguments passed to the function into a single array called `args`. Since JavaScript arrays have a built-in `length` property, the function simply returns `args.length` to get the count of arguments. This approach handles zero or more arguments naturally, as the rest parameter will create an empty array if no arguments are provided, or an array containing all arguments otherwise.

## Complexity

- **Time:** O(1)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-11 07:54 UTC
- Runtime: 53 ms
- Memory: 49 MB
- Language: JavaScript
