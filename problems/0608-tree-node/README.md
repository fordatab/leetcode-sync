# Tree Node

**Difficulty:** Medium
**Tags:** sql, self-join, tree, case-statement

## Problem

Given a table representing a tree structure where each row contains a node's ID and its parent's ID, classify each node as one of three types: 'Root' (has no parent), 'Leaf' (has a parent but no children), or 'Inner' (has both a parent and at least one child). The table is guaranteed to represent a valid tree structure.

## Approach

The solution uses a self-join approach to determine node types. It joins the `tree` table with itself where `t1.id = t2.p_id`, effectively matching each node in `t1` with any children it might have in `t2`. The LEFT JOIN ensures all nodes from `t1` appear in the result even if they have no children.

A CASE statement then classifies each node:
- If `p_id` is NULL, the node is the root (no parent)
- If `p_id` is NOT NULL and the join found a matching child (`t2.id` is NOT NULL), it's an inner node
- If `p_id` is NOT NULL but no children were found (`t2.id` is NULL), it's a leaf node

The DISTINCT keyword handles cases where a node has multiple children (which would create multiple rows in the join result), ensuring each node appears only once in the output.

## Complexity

- **Time:** O(n²)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-23 22:41 UTC
- Runtime: 1477 ms
- Memory: 0B
- Language: MySQL
