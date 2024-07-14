# Merge Nodes in Between Zeros

**Difficulty:** Medium
**Tags:** linked-list, two-pointers, simulation

## Problem

Given a linked list that starts and ends with zeros, and contains integers separated by zeros, transform it by replacing each segment between consecutive zeros with a single node containing the sum of all values in that segment. The resulting list should not contain any zeros. The list is guaranteed to have at least 3 nodes, all node values are between 0 and 1000, and there are no two consecutive zeros except at boundaries.

## Approach

The solution uses a single-pass traversal with a dummy head pattern. Starting from the node after the initial zero, it iterates through the list maintaining a running sum `c`. When encountering a non-zero value, it adds that value to the current sum. When encountering a zero, it creates a new node with the accumulated sum, appends it to the result list, and resets the sum to zero. A dummy node simplifies list construction by providing a stable starting point, and the final answer is returned via `dummy.next`. The algorithm processes each segment between zeros sequentially, building the new list as it goes.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-14 06:06 UTC
- Runtime: 675 ms
- Memory: 279.5 MB
- Language: C++
