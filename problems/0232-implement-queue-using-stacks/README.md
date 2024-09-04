# Implement Queue using Stacks

**Difficulty:** Easy
**Tags:** stack, queue, design, amortized-analysis

## Problem

Design a queue data structure using only two stacks as the underlying storage mechanism. The queue must support standard FIFO operations: enqueue (push), dequeue (pop), peek at the front element, and check if empty. Each element is an integer between 1 and 9, and at most 100 total operations will be performed. All pop and peek calls are guaranteed to be valid (called on non-empty queues).

## Approach

This solution uses two stacks named `i` (input) and `o` (output) to simulate queue behavior.

**Push operation**: New elements are always pushed onto the input stack `i`, making enqueue O(1).

**Pop and Peek operations**: These leverage a lazy transfer strategy. When we need to access the front of the queue, we check if the output stack `o` is empty. If it is, we transfer all elements from `i` to `o` by popping from `i` and pushing to `o`. This reversal means the oldest element (queue front) is now at the top of `o`. The `pop` method calls `peek` first to ensure the output stack is populated, then removes and returns the top element.

**Empty check**: The queue is empty only when both stacks are empty.

This approach achieves amortized O(1) time for all operations because each element is moved between stacks at most once—from `i` to `o`—so the cost of transfers is distributed across multiple operations.

## Complexity

- **Time:** O(1) amortized for all operations
- **Space:** O(n)

## Stats

- Submitted: 2024-09-04 01:45 UTC
- Runtime: 0 ms
- Memory: 8.6 MB
- Language: C++
