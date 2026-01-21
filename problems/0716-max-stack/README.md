# Max Stack

**Difficulty:** Hard
**Tags:** linked-list, doubly-linked-list, ordered-set, stack, design

## Problem

Design a stack that supports standard push, pop, and top operations, plus peekMax (returning the maximum element) and popMax (removing and returning the maximum element, specifically the top-most one if there are duplicates). The constraints specify up to 10^5 operations with element values ranging from -10^7 to 10^7, and require O(1) time for top and O(log n) for other operations.

## Approach

The solution maintains a doubly-linked list with sentinel head and tail nodes to represent the stack order, where elements are inserted before the tail (so tail->prev gives the top). Simultaneously, it uses a C++ `set` storing pairs of `(value, node_pointer)` to efficiently track elements sorted by value.

For `push`, a new node is created and inserted before the tail in the linked list, and the (value, node) pair is added to the set. The `top` operation simply returns the value of `tail->prev`. For `pop`, the top node (before tail) is removed from both the linked list and the set.

`peekMax` retrieves the maximum by accessing the last element in the set (`rbegin()`), which gives O(log n) access. For `popMax`, the code finds the maximum entry in the set, extracts its node pointer, removes that node from anywhere in the doubly-linked list (by adjusting prev/next pointers), and erases it from the set. The set naturally handles duplicates by including the node pointer in the pair, ensuring each entry is unique and the rightmost (top-most) duplicate appears last when iterating backward.

The doubly-linked list enables O(1) removal from any position once the node is located, and the set provides O(log n) insertion, deletion, and max-finding operations.

## Complexity

- **Time:** O(1) for top, O(log n) for push, pop, peekMax, and popMax
- **Space:** O(n)

## Stats

- Submitted: 2026-01-21 22:23 UTC
- Runtime: 82 ms
- Memory: 146 MB
- Language: C++
