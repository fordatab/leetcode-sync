# Build Array from Permutation

**Difficulty:** Easy
**Tags:** array, simulation, permutation

## Problem

Given an array representing a zero-based permutation (where each element is a distinct integer from 0 to n-1), construct a new array where each position i contains the value at the index pointed to by nums[i]. The array length is between 1 and 1000, and all elements are guaranteed to be valid indices within the array bounds.

## Approach

The solution uses a straightforward transformation approach. It creates a new output vector and iterates through each index of the input array. For each position, it performs a double-indexing operation: first using the current index to access nums, then using that value as another index into nums (i.e., nums[nums[x]]). Each computed value is appended to the output vector, which is returned after processing all elements. This direct mapping builds the required permutation in a single pass through the input.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-14 06:13 UTC
- Runtime: 14 ms
- Memory: 19.5 MB
- Language: C++
