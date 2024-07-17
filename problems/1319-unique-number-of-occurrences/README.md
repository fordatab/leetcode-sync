# Unique Number of Occurrences

**Difficulty:** Easy
**Tags:** hash-table, hash-set, counting, array

## Problem

Given an array of integers with values ranging from -1000 to 1000 and length up to 1000, determine whether each distinct value appears a unique number of times. Return true if all occurrence counts are different from each other, false otherwise.

## Approach

The solution uses a two-phase approach with hash-based data structures:

1. **Count occurrences**: First, iterate through the input array and use an unordered map to count how many times each distinct value appears. The map keys are the array values, and the map values are their occurrence counts.

2. **Check uniqueness**: Next, iterate through the map and insert all occurrence counts into an unordered set. Since sets automatically deduplicate elements, if two different values had the same occurrence count, the set would contain fewer elements than the map.

3. **Compare sizes**: Finally, compare the size of the set (unique occurrence counts) with the size of the map (number of distinct values). If they're equal, all occurrence counts are unique; otherwise, at least two values share the same count.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-17 08:24 UTC
- Runtime: 0 ms
- Memory: 11.6 MB
- Language: C++
