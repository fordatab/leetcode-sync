# Odd Even Linked List

**Difficulty:** Medium
**Tags:** linked-list, two-pointers, in-place-manipulation

## Problem

Given a singly linked list, rearrange the nodes so that all nodes at odd positions (1st, 3rd, 5th, etc.) come before all nodes at even positions (2nd, 4th, 6th, etc.), while preserving the relative order within each group. The list can contain up to 10,000 nodes with values ranging from -1,000,000 to 1,000,000. The solution must use O(1) extra space and O(n) time.

## Approach

The solution uses two dummy head nodes to build separate chains for odd-indexed and even-indexed nodes. It maintains two pointers (`a` and `b`) that track the current tail of each chain, starting from dummy nodes `odds` and `evens`.

As it iterates through the original list with a counter `c`, it alternates between appending nodes to the odd chain (when `c % 2 == 0`, since the counter starts at 0) and the even chain (when `c % 2 == 1`). After processing all nodes, it sets the `next` pointers of both chain tails to `nullptr` to properly terminate them.

Finally, it connects the tail of the odd chain to the head of the even chain (skipping the even dummy node) and returns the head of the odd chain (skipping the odd dummy node). The code includes some debug `cout` statements that would print during execution.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-17 08:16 UTC
- Runtime: 10 ms
- Memory: 15.4 MB
- Language: C++
