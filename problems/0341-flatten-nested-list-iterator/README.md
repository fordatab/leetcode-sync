# Flatten Nested List Iterator

**Difficulty:** Medium
**Tags:** stack, iterator, nested-structure, design

## Problem

Design an iterator that flattens a nested list structure where each element can be either an integer or another list (which may contain integers or further nested lists). The iterator must support hasNext() to check if more integers exist and next() to retrieve the next integer in flattened order. The nested list can have up to 500 elements at the top level, with integer values ranging from -10^6 to 10^6.

## Approach

The solution uses a stack-based iterative approach to flatten the nested structure on-demand. During initialization, all top-level elements are pushed onto a stack in reverse order (to maintain left-to-right traversal). The key insight is that `hasNext()` does the heavy lifting: it processes the stack by checking the top element — if it's an integer, we're ready to return true; if it's a list, we pop it and push its children in reverse order onto the stack. This "lazy" expansion continues until we find an integer or exhaust the stack. The `next()` method simply pops and returns the integer at the top, relying on `hasNext()` having already ensured the top is an integer.

## Complexity

- **Time:** O(n)
- **Space:** O(d)

## Stats

- Submitted: 2024-09-26 01:13 UTC
- Runtime: 8 ms
- Memory: 16 MB
- Language: C++
