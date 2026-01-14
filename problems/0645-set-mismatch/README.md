# Set Mismatch

**Difficulty:** Easy
**Tags:** hash-table, array, counting

## Problem

Given an array that should contain integers from 1 to n but has one duplicate and one missing number due to an error, identify both the duplicated number and the missing number. The array has length n (2 ≤ n ≤ 10⁴), and each element is between 1 and 10⁴.

## Approach

The solution uses a hash map to track the frequency difference for each number from 1 to n.

First, it initializes the map with all numbers 1 through n, each having a count of 1. Then it iterates through the input array and decrements the count for each number encountered.

After processing, numbers in the map will have different values: a count of -1 indicates the duplicate (appeared in nums but was already counted), while a count of 1 indicates the missing number (never appeared in nums, so its initial count remains).

Finally, it scans the map to find which number has count -1 (duplicate) and which has count 1 (missing), returning them as a vector.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2026-01-14 05:29 UTC
- Runtime: 31 ms
- Memory: 34.7 MB
- Language: C++
