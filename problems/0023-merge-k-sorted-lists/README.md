# Merge k Sorted Lists

**Difficulty:** Hard
**Tags:** linked-list, heap, priority-queue, merge, sorting

## Problem

Given an array of k linked lists where each list is already sorted in ascending order, merge all lists into a single sorted linked list and return it. The number of lists k can range from 0 to 10,000, each list can have up to 500 nodes, and node values range from -10,000 to 10,000. The total number of nodes across all lists will not exceed 10,000.

## Approach

The solution uses a min-heap (priority queue) to collect all nodes from all input lists. It iterates through each linked list in the input array, traversing each list completely and pushing every node along with its value as a pair into the priority queue. The priority queue automatically maintains nodes in ascending order based on their values.

After all nodes are collected in the heap, the solution repeatedly extracts the minimum element (top of the heap) and appends it to the result list by linking it to the current tail pointer. This process continues until the heap is empty.

A dummy head node is used to simplify list construction, and the final merged list is returned by accessing `dummy.next`. The key insight is to leverage the heap's ordering property to always select the next smallest node, though this implementation differs from the typical approach by loading all nodes upfront rather than maintaining only k elements (the head of each list) in the heap.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-15 00:08 UTC
- Runtime: 27 ms
- Memory: 19.1 MB
- Language: C++
