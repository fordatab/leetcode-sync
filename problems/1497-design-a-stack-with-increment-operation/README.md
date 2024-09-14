# Design a Stack With Increment Operation

**Difficulty:** Medium
**Tags:** stack, array, design

## Problem

Implement a bounded stack that supports standard push and pop operations, plus an increment operation that adds a value to the bottom k elements. The stack has a maximum capacity and rejects pushes when full. Pop returns -1 when the stack is empty, and increment affects all elements if there are fewer than k elements present.

## Approach

The solution uses a `vector<int>` to represent the stack and stores the maximum size separately. Push appends to the vector only if the current size is below the limit. Pop checks for emptiness, retrieves the last element, removes it, and returns it (or -1 if empty). The increment operation iterates through the first k elements (or all elements if fewer than k exist) and adds the value directly to each element in-place. This is a straightforward array-based stack implementation with a naive O(k) increment that modifies elements directly rather than using lazy propagation.

## Complexity

- **Time:** O(1) for push and pop, O(k) for increment
- **Space:** O(maxSize)

## Stats

- Submitted: 2024-09-14 04:46 UTC
- Runtime: 31 ms
- Memory: 25.9 MB
- Language: C++
