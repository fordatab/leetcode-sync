# Split Linked List in Parts

**Difficulty:** Medium
**Tags:** linked-list, two-pointer, array

## Problem

Given a singly linked list and an integer k, partition the list into k consecutive segments. The segments should have sizes as equal as possible, with at most one node difference between any two parts. Earlier segments should be at least as large as later ones, and some segments may be empty if k exceeds the list length.

## Approach

The solution first counts the total number of nodes in the list by traversing it once. It then calculates the base size for each part (total nodes divided by k) and determines how many parts need an extra node (the remainder of the division).

For each of the k parts, the code uses a dummy node technique to build a new segment. It iterates through the base number of nodes, disconnecting them from the original list and linking them to form the current part. If there are still extra nodes to distribute (tracked by decrementing the remainder), one additional node is added to the current part.

After forming each part, the code properly terminates it by setting the last node's next pointer to nullptr, ensuring each segment is independent. The head pointer advances through the original list as nodes are consumed, and the resulting k parts are stored in a vector.

## Complexity

- **Time:** O(n)
- **Space:** O(k)

## Stats

- Submitted: 2024-08-23 04:31 UTC
- Runtime: 10 ms
- Memory: 13.9 MB
- Language: C++
