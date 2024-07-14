# Copy List with Random Pointer

**Difficulty:** Medium
**Tags:** linked-list, hash-table, deep-copy, two-pass

## Problem

Given a linked list where each node has a value, a next pointer, and an additional random pointer (which may point to any node in the list or be null), create a complete deep copy of this structure. The copied list must use entirely new node objects, with all next and random pointers correctly mapped to corresponding nodes in the new list rather than pointing back to the original list. The list can contain up to 1000 nodes with values between -10^4 and 10^4.

## Approach

The solution uses a hash map to maintain a mapping from original nodes to their newly created copies. It performs two passes through the original list:

**First pass:** Traverse the original list and create a new node for each original node, storing the mapping in an unordered_map. The map also explicitly stores nullptr -> nullptr to handle null pointers cleanly.

**Second pass:** Traverse the original list again, and for each original node, set the next and random pointers of its corresponding copy by looking up the target nodes in the hash map. Since all nodes were created in the first pass, both `nodes[a->next]` and `nodes[a->random]` will always find valid entries (including nullptr).

Finally, return the copied head by looking up the original head in the map. This approach ensures all pointer relationships are preserved in the deep copy.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-14 22:42 UTC
- Runtime: 11 ms
- Memory: 15.2 MB
- Language: C++
