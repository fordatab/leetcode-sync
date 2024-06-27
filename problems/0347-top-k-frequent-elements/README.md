# Top K Frequent Elements

**Difficulty:** Medium
**Tags:** hash-table, heap, frequency-counting, sorting

## Problem

Given an array of integers and a target count k, identify the k numbers that appear most frequently in the array. The array can contain up to 100,000 elements with values between -10,000 and 10,000, and k is guaranteed to be valid (between 1 and the count of distinct elements). The output order doesn't matter.

## Approach

The solution uses a frequency-counting approach combined with a heap-based selection:

1. **Frequency Counting**: First, iterate through the input array and build a hash map (`unordered_map`) where keys are the array elements and values are their occurrence counts.

2. **Heap Construction**: Convert the map into a vector of pairs, where each pair contains the frequency as the first element and the value as the second element. This ordering ensures the heap prioritizes by frequency.

3. **Max-Heap Formation**: Use `make_heap` to transform the vector into a max-heap in-place. This creates a heap structure where the most frequent elements bubble to the top.

4. **Extracting Top K**: Perform k iterations of `pop_heap` followed by `pop_back`, which extracts the maximum element (highest frequency) each time. Collect the actual values (second element of each pair) into the result vector.

## Complexity

- **Time:** O(n + m log m)
- **Space:** O(m)

## Stats

- Submitted: 2024-06-27 07:30 UTC
- Runtime: 16 ms
- Memory: 17.2 MB
- Language: C++
