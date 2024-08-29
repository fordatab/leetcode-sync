# Remove Duplicates from Sorted List II

**Difficulty:** Medium
**Tags:** linked-list, two-pointers, dummy-node

## Problem

Given a sorted singly linked list, remove all nodes whose values appear more than once, keeping only nodes with unique values. The list has at most 300 nodes with values between -100 and 100. The result should remain sorted.

## Approach

The solution uses a dummy node to simplify edge cases where the head itself might be removed. It maintains two pointers: `a` tracks the last node known to be unique (or the dummy), and `cur` scans ahead to detect duplicates.

When `cur` and `cur->next` have the same value, the code identifies the duplicate value and advances `cur` past all nodes with that value using a while loop. It then updates `a->next` to skip over the entire duplicate sequence.

When no duplicate is detected, both `a` and `cur` advance by one position, effectively keeping the current node in the result list. The dummy node's `next` pointer ultimately points to the cleaned list.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-29 08:51 UTC
- Runtime: 8 ms
- Memory: 15.5 MB
- Language: C++
