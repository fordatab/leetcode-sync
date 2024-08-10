# Design Cancellable Function

**Difficulty:** Hard
**Tags:** generator, async-await, promise, error-handling, concurrency

## Problem

The task is to implement a cancellable wrapper for JavaScript generator functions that yield promises. The wrapper returns a cancel function and a promise, where calling cancel throws a "Cancelled" string error into the generator. The generator's yielded promises must be resolved and their values passed back to the generator via next(), and any rejections or the cancellation error must be thrown back via throw(). The returned promise resolves with the generator's final return value or rejects with any uncaught error.

## Approach

The solution creates a cancel function and a cancelPromise that rejects with "Cancelled" when invoked. An async IIFE drives the generator forward by repeatedly calling `generator.next()` with the resolved value from the previously yielded promise. Each iteration uses `Promise.race()` between the current yielded promise and the cancelPromise, so if cancel is called, the race settles with the "Cancelled" rejection. This rejection is caught and thrown back into the generator via `generator.throw()`, allowing the generator's try-catch blocks to handle cancellation. The loop continues until the generator is done (next.done is true), at which point the final value is returned. If any error propagates out of the generator without being caught, the outer promise rejects naturally.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-10 21:43 UTC
- Runtime: 52 ms
- Memory: 49.2 MB
- Language: JavaScript
