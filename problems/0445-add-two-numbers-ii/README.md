# Add Two Numbers II

**Difficulty:** Medium
**Tags:** linked-list, stack, math, two-pointers

## Problem

Given two linked lists where each node contains a single digit and the most significant digit appears first, compute their sum and return it as a linked list. Each list represents a non-negative integer without leading zeros (except for zero itself). The lists can have between 1 and 100 nodes, with node values from 0 to 9.

## Approach

The solution uses two stacks to process the digits from least significant to most significant without reversing the lists. It pushes all nodes from both lists onto separate stacks (including dummy head nodes). Then it pops from both stacks simultaneously, adding corresponding digits plus any carry, and storing results back into the nodes of the first list. After processing common digits, if one list is longer, it continues propagating the carry through the remaining stack. The key insight is using stacks to access digits in reverse order (from end to start) while reusing the existing list nodes to build the result. The dummy nodes help handle edge cases where the result has more digits than either input.

## Complexity

- **Time:** O(max(m, n))
- **Space:** O(m + n)

## Stats

- Submitted: 2024-08-14 05:30 UTC
- Runtime: 51 ms
- Memory: 80.6 MB
- Language: C++
