# Throne Inheritance

**Difficulty:** Medium
**Tags:** tree, depth-first-search, hash-table, design

## Problem

Design a system to track royal inheritance order in a kingdom. The system must handle births (adding children to parents), deaths (marking individuals as deceased without removing them from the tree), and queries for the current inheritance order. The inheritance follows a depth-first preorder traversal of the family tree, excluding deceased members from the final output. Operations must efficiently support up to 10^5 births/deaths and up to 10 inheritance order queries.

## Approach

The solution uses a tree structure where each node represents a family member with their name, alive status, and list of children. A hash map provides O(1) lookup from names to nodes. 

For births, a new node is created and added to the parent's children list (maintaining birth order). The hash map is updated with the new child. 

For deaths, the node's alive flag is set to false without removing it from the tree structure.

For inheritance order queries, a depth-first search performs preorder traversal starting from the king (root). The DFS visits each node, adds living members to the result list, then recursively visits all children in order. This naturally produces the correct inheritance sequence: a person is followed by all their descendants before moving to their siblings.

## Complexity

- **Time:** O(n) per getInheritanceOrder call where n is total family members; O(1) for birth and death operations
- **Space:** O(n) for storing the tree and hash map

## Stats

- Submitted: 2025-11-29 09:29 UTC
- Runtime: 134 ms
- Memory: 174.3 MB
- Language: C++
