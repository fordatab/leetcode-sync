# Min Stack

**Difficulty:** Medium
**Tags:** stack, design, monotonic-stack

## Problem

Implement a stack data structure that provides standard stack operations (push, pop, top) along with an additional operation to retrieve the minimum element, where all operations must execute in constant time. The stack stores integers in the range of a 32-bit signed integer, and operations on an empty stack are guaranteed not to occur except for push.

## Approach

The solution uses a vector of pairs where each pair stores both the pushed value and the minimum value present in the stack up to that point. When pushing a new element, the code compares it with the previous minimum (stored in the second element of the last pair) and stores the smaller value alongside the new element. This ensures that at any stack state, the top pair contains both the most recent value and the current minimum. The pop operation simply removes the last pair, the top operation returns the first element of the last pair, and getMin returns the second element of the last pair. This augmented storage strategy trades space for constant-time minimum retrieval without requiring a separate auxiliary stack.

## Complexity

- **Time:** O(1)
- **Space:** O(n)

## Stats

- Submitted: 2024-06-28 05:26 UTC
- Runtime: 15 ms
- Memory: 19.9 MB
- Language: C++
