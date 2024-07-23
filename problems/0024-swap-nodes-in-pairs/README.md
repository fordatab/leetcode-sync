# Swap Nodes in Pairs

**Difficulty:** Medium
**Tags:** linked-list, pointer-manipulation, iterative

## Problem

Given a singly-linked list, rearrange it by swapping every pair of adjacent nodes and return the new head. The swapping must be done by changing node pointers, not by modifying the node values. The list can contain 0 to 100 nodes with values between 0 and 100.

## Approach

The solution uses an iterative pointer-manipulation approach with a dummy head node. It maintains three pointers: `a` (the node before the pair to swap), `n` (the first node of the current pair), and accesses `n->next` (the second node of the pair). For each pair:

- Store the node after the pair (`tmp = n->next->next`)
- Redirect `a->next` to point to the second node (`n->next`)
- Make the second node point back to the first node (`n->next->next = n`)
- Connect the first node to what comes after the pair (`n->next = tmp`)
- Advance the pointers: `a` becomes the first node (now in second position), and `n` advances to the next unprocessed node

The loop continues while there are at least two nodes remaining to swap. The dummy node simplifies handling the new head, which is returned as `dummy.next`.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-23 20:14 UTC
- Runtime: 5 ms
- Memory: 10.6 MB
- Language: C++
