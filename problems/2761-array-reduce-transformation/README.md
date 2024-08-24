# Array Reduce Transformation

**Difficulty:** Easy
**Tags:** array, iteration, accumulator, functional-programming

## Problem

Implement a custom array reduction function that processes each element of an integer array sequentially through a provided reducer function, accumulating results from an initial value. The function must handle arrays up to 1000 elements with values from 0 to 1000, returning the initial value unchanged for empty arrays, without using the built-in Array.reduce method.

## Approach

The solution implements a straightforward iterative approach to mimic the reduce operation. It initializes an accumulator variable `val` with the provided `init` value, then iterates through the input array using a standard for-loop. During each iteration, it updates the accumulator by calling the reducer function `fn` with the current accumulator value and the current array element, storing the result back in `val`. After processing all elements (or immediately if the array is empty), it returns the final accumulated value.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-24 00:38 UTC
- Runtime: 59 ms
- Memory: 49.5 MB
- Language: JavaScript
