# Sort List

**Difficulty:** Medium
**Tags:** linked-list, merge-sort, two-pointers, divide-and-conquer, recursion

## Problem

Given the head of a singly linked list, sort it in ascending order and return the sorted list. The list can contain up to 50,000 nodes with values ranging from -100,000 to 100,000. The challenge is to achieve O(n log n) time complexity with O(1) auxiliary space.

## Approach

This solution implements merge sort on a linked list using a recursive top-down approach.

**Splitting the list:** The code uses the slow-and-fast pointer technique to find the midpoint. A slow pointer moves one step at a time while a fast pointer moves two steps. When the fast pointer reaches the end, the slow pointer is at the middle. The list is then split at this midpoint by setting `prev->next = nullptr`.

**Base cases:** The recursion handles two base cases: (1) empty or single-node lists are already sorted, and (2) two-node lists are sorted with a simple swap if needed. The latter is an optimization to avoid deeper recursion for the smallest sublists.

**Recursive sorting:** Once split into left and right halves, the function recursively sorts each half by calling `sortList` on both sublists.

**Merging:** The sorted halves are merged using a recursive `merge` function that compares the heads of both lists, selects the smaller node, and recursively merges the remainder. This builds the final sorted list by chaining nodes in ascending order.

Note: While the merge uses recursive calls that consume O(log n) call stack space, this doesn't achieve the O(1) space complexity suggested in the follow-up.

## Complexity

- **Time:** O(n log n)
- **Space:** O(log n)

## Stats

- Submitted: 2024-08-24 04:25 UTC
- Runtime: 237 ms
- Memory: 58.2 MB
- Language: C++
