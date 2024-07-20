# Maximum Twin Sum of a Linked List

**Difficulty:** Medium
**Tags:** linked-list, array, two-pointers

## Problem

Given a singly linked list with an even number of nodes, find the maximum sum among all twin pairs. Twin nodes are defined symmetrically: the i-th node (0-indexed) pairs with the (n-1-i)-th node, where n is the total number of nodes. The list has between 2 and 100,000 nodes, and each node's value is between 1 and 100,000.

## Approach

The solution traverses the linked list once to collect all node values into a vector while counting the total number of nodes. After building this array representation, it iterates through the first half of the list (though the loop actually goes through all indices) and computes the sum of each element with its mirror element from the end of the array using the formula `vals[y] + vals[x-y-1]`. Throughout this process, it maintains the maximum twin sum encountered. This converts the linked list problem into an array-based problem where twin pairs can be accessed via symmetric indexing.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-20 06:46 UTC
- Runtime: 179 ms
- Memory: 129.3 MB
- Language: C++
