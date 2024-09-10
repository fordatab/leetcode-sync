# Insert Delete GetRandom O(1)

**Difficulty:** Medium
**Tags:** hash-table, array, design, randomized

## Problem

Design a data structure that supports inserting elements, removing elements, and retrieving a random element, all in average O(1) time. The structure must ensure each element has equal probability of being selected when getting a random element. Values are 32-bit integers and up to 200,000 operations may be performed.

## Approach

The solution uses a combination of a vector and an unordered map to achieve O(1) average time for all operations.

- **Insert**: Check if the value exists in the map. If not, append it to the vector and store its index in the map.

- **Remove**: If the value exists, perform a swap-and-pop trick: move the last element in the vector to the position of the element being removed, update the map entry for that last element to reflect its new position, then pop the last element from the vector and erase the removed value from the map.

- **GetRandom**: Generate a random index within the vector's bounds and return the element at that index. Since the vector maintains all current elements contiguously, this ensures uniform probability.

The key insight is that the vector provides O(1) random access and the map provides O(1) lookup and index tracking, while the swap-with-last technique maintains O(1) removal without creating gaps in the vector.

## Complexity

- **Time:** O(1)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-10 03:43 UTC
- Runtime: 166 ms
- Memory: 101.9 MB
- Language: C++
