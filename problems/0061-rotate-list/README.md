# Rotate List

**Difficulty:** Medium
**Tags:** linked-list, two-pointers, circular-list

## Problem

Given a singly-linked list and a non-negative integer k, perform a right rotation by k positions, moving the last k nodes to the front. The list can have 0 to 500 nodes with values between -100 and 100, and k can be as large as 2×10⁹, requiring modulo optimization to handle cases where k exceeds the list length.

## Approach

The solution first handles the edge case of an empty list. It then traverses the entire list to calculate its length `s` while keeping a pointer `n` to the last node. If the list has only one element, it returns immediately. The rotation count is reduced modulo the list length to avoid unnecessary full rotations. If the effective rotation is zero, the original head is returned.

To perform the rotation, the code finds the new tail position by traversing `s - k - 1` steps from the head. The node at this position (`o`) becomes the new tail, and the node after it (`r`) becomes the new head. The old tail (`n`) is connected to the original head to form a circular structure temporarily, and then the new tail's `next` pointer is set to `nullptr` to break the cycle. This effectively moves the last k nodes to the front.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-23 03:53 UTC
- Runtime: 0 ms
- Memory: 16.6 MB
- Language: C++
