# Group the People Given the Group Size They Belong To

**Difficulty:** Medium
**Tags:** array, hash-table, greedy, grouping

## Problem

Given an array where each element indicates the required group size for the person at that index, partition all people (represented by their indices) into groups such that each person ends up in a group of their specified size. The solution must place every person in exactly one group, and any valid grouping is acceptable.

## Approach

The solution uses a bucketing strategy followed by a chunking phase. First, it creates a vector of vectors indexed by group size, where `groups[k]` collects all person IDs that need to be in groups of size `k`. It iterates through the input array once, placing each person's ID into the bucket corresponding to their required group size.

In the second phase, it processes each bucket sequentially. For bucket index `a` (representing group size `a`), it chunks the collected person IDs into groups of exactly size `a`. This is done by checking if the current position `x` is a multiple of `a` (using `x % a == 0`), which signals the completion of one group and the start of another. Each completed chunk is added to the output.

The key insight is that people requiring the same group size can be arbitrarily grouped together in chunks of that size, since the problem guarantees a valid solution exists and doesn't constrain which specific people must be grouped together.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-05 00:00 UTC
- Runtime: 3 ms
- Memory: 16.2 MB
- Language: C++
