# Merge Two Sorted Lists

**Difficulty:** Easy
**Tags:** linked-list, two-pointers, merge

## Problem

Given two singly linked lists that are already sorted in ascending order, combine them into a single sorted linked list by rearranging the existing nodes (not creating new ones). Each list can contain 0 to 50 nodes with values between -100 and 100. Return the head of the merged result.

## Approach

The solution uses a dummy head node to simplify edge cases and a tail pointer to build the merged list iteratively. It compares the current nodes from both input lists in a while loop, appending the smaller node to the result and advancing that list's pointer. The tail pointer moves forward after each append to maintain the position where the next node should be attached. Once one list is exhausted, the remaining nodes from the other list (which are already sorted and larger than all previously merged nodes) are directly attached to the tail. Finally, the merged list is returned starting from the node after the dummy head.

## Complexity

- **Time:** O(n + m)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-01 00:54 UTC
- Runtime: 8 ms
- Memory: 18.3 MB
- Language: C++
