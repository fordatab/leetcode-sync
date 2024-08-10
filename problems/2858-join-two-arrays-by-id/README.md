# Join Two Arrays by ID

**Difficulty:** Medium
**Tags:** hash-table, array, object-merging

## Problem

Given two arrays of objects where each object has an 'id' field, merge them by id. Objects with unique ids appear as-is, while objects sharing an id are merged with arr2's properties overriding arr1's properties for conflicting keys. The result must be sorted in ascending order by id, containing one object per unique id across both input arrays.

## Approach

The solution uses a hashmap (plain object) to store merged results keyed by id. First, it iterates through arr1 and stores each object using its id as the key. Then it processes arr2: if an id already exists in the result, it iterates through all keys in the arr2 object and overwrites the corresponding properties in the result object (achieving the merge with arr2 precedence); if the id is new, it simply adds the arr2 object to the result. Finally, Object.values() extracts all merged objects from the hashmap. JavaScript's Object.values() maintains insertion order for integer-like keys in ascending numeric order, which provides the required sorting.

## Complexity

- **Time:** O(n + m + k)
- **Space:** O(n + m)

## Stats

- Submitted: 2024-08-10 21:48 UTC
- Runtime: 269 ms
- Memory: 89.9 MB
- Language: JavaScript
