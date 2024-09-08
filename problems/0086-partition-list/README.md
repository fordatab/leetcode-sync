# Partition List

**Difficulty:** Medium
**Tags:** linked-list, two-pointers, partition

## Problem

Given a linked list and a partition value x, rearrange the list so that all nodes with values less than x appear before all nodes with values greater than or equal to x. The relative order of nodes within each partition must be preserved. The list can contain 0 to 200 nodes with values between -100 and 100, and x ranges from -200 to 200.

## Approach

The solution uses a two-pointer technique to build two separate linked lists: one for nodes with values less than x, and another for nodes with values greater than or equal to x.

Two dummy head nodes (`lt` and `gte`) are created to simplify list construction. As we traverse the original list, each node is appended to either the "less than" list (via pointer `l`) or the "greater than or equal" list (via pointer `g`) based on its value compared to x.

After processing all nodes, the "greater than or equal" list is properly terminated with a null pointer to prevent cycles. The tail of the "less than" list is then connected to the head of the "greater than or equal" list, creating the final partitioned result.

The function returns `lt.next`, which points to the first actual node of the partitioned list (skipping the dummy head).

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-08 02:38 UTC
- Runtime: 0 ms
- Memory: 14.8 MB
- Language: C++
