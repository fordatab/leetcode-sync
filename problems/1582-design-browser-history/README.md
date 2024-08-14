# Design Browser History

**Difficulty:** Medium
**Tags:** linked-list, doubly-linked-list, design, data-structure

## Problem

Design a browser history system that supports navigating between URLs. The system starts at a homepage and allows visiting new URLs (which clears forward history), moving backward through previously visited pages, and moving forward through pages that were navigated away from. Navigation operations are bounded by the actual history available, meaning you can only go back or forward as far as the history extends.

## Approach

The solution uses a doubly-linked list where each node stores a URL string. The `history` pointer tracks the current page position. When visiting a new URL, the code deletes all nodes forward of the current position (clearing forward history), creates a new node for the URL, links it to the current node, and advances the current pointer. The `back` operation walks backward through the linked list up to the specified number of steps or until reaching the beginning, updating the current pointer. Similarly, `forward` walks forward through existing nodes up to the specified steps or until reaching the end. Both navigation methods return the URL at the final position.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-14 21:38 UTC
- Runtime: 117 ms
- Memory: 63.5 MB
- Language: C++
