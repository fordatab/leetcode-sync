# Insert Greatest Common Divisors in Linked List

**Difficulty:** Medium
**Tags:** linked-list, two-pointers, math, gcd

## Problem

Given a singly linked list where each node holds an integer, insert a new node between every pair of consecutive nodes. The value of each inserted node should be the greatest common divisor (GCD) of its two neighboring nodes. The list can have between 1 and 5000 nodes, with values ranging from 1 to 1000.

## Approach

The solution uses a two-pointer technique to traverse the linked list. It maintains two pointers: `first` pointing to the current node and `second` pointing to the next node. For each adjacent pair, it computes their GCD using the built-in `__gcd` function, creates a new node with this GCD value, and inserts it between the two nodes by adjusting the `next` pointers. After insertion, `first` is moved two steps forward (skipping over the newly inserted node) to point to what was originally `second`, and `second` advances to the next node. This continues until `second` becomes null, indicating the end of the list.

## Complexity

- **Time:** O(n log m)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-19 03:21 UTC
- Runtime: 30 ms
- Memory: 35.5 MB
- Language: C++
