# Generate Fibonacci Sequence

**Difficulty:** Easy
**Tags:** generator, fibonacci, iterator, math

## Problem

The task is to implement a JavaScript generator function that yields successive numbers from the Fibonacci sequence, where each number is the sum of the two preceding ones (starting with 0 and 1). The generator should continue indefinitely, producing values on demand when next() is called, up to a maximum of 50 calls.

## Approach

The solution uses a JavaScript generator function with an infinite loop that yields Fibonacci numbers one at a time. It maintains two variables: `current` holds the value to be yielded next, and `next` holds the following Fibonacci number. After each yield, it updates both variables using destructuring assignment: `current` becomes the old `next`, and `next` becomes the sum of the old `current` and old `next`. This pattern allows the generator to produce the sequence indefinitely without storing the entire sequence in memory, generating each value only when requested via the iterator protocol.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-10 21:39 UTC
- Runtime: 56 ms
- Memory: 49.2 MB
- Language: JavaScript
