# Partition Labels

**Difficulty:** Medium
**Tags:** greedy, hash-table, two-pointer, string

## Problem

Given a string of lowercase letters, partition it into the maximum number of substrings such that each character appears in at most one partition. The partitions must maintain the original order when concatenated. Return the lengths of these partitions. The string length is between 1 and 500 characters.

## Approach

The solution uses a greedy approach with a hashmap to track the last occurrence of each character. First, it scans the string backwards to record the rightmost index where each character appears. Then it iterates through the string from left to right, maintaining a current partition boundary. For each position, it looks up the last occurrence of the current character and extends the partition boundary to include all characters between the start and this last occurrence. As it scans within a partition, it continuously updates the boundary to the maximum last-occurrence index of any character encountered, ensuring all instances of every character in the partition are included. When reaching the boundary, it records the partition length and starts a new partition from the next position.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-25 02:17 UTC
- Runtime: 11 ms
- Memory: 9.3 MB
- Language: C++
