# Implement Stack using Queues

**Difficulty:** Easy
**Tags:** queue, stack, design, simulation

## Problem

Implement a stack (LIFO data structure) using only queue operations. The stack must support push, pop, top, and empty operations, where push adds an element to the top, pop removes and returns the top element, top returns the top element without removing it, and empty checks if the stack is empty. All operations on pop and top are guaranteed to be valid, and at most 100 operations will be performed.

## Approach

This solution uses a single queue and maintains the LIFO order by rotating elements during each push operation. When a new element is pushed, it's first added to the back of the queue. Then, all elements that were previously in the queue are removed from the front and re-added to the back, effectively reversing their order. This means the most recently pushed element ends up at the front of the queue.

For example, if the queue contains [1, 2] and we push 3, we first add 3 to get [1, 2, 3], then rotate by moving 1 and 2 to the back, resulting in [3, 1, 2]. Now the newest element (3) is at the front, ready to be popped.

The pop operation simply removes and returns the front element of the queue, which is the most recently pushed element. Similarly, top returns the front element without removing it. The empty operation directly checks if the queue is empty.

This approach makes push O(n) time complexity since it rotates n-1 elements, while pop, top, and empty are all O(1) operations.

## Complexity

- **Time:** O(n) for push, O(1) for pop/top/empty
- **Space:** O(n)

## Stats

- Submitted: 2024-08-22 07:56 UTC
- Runtime: 0 ms
- Memory: 8.5 MB
- Language: C++
