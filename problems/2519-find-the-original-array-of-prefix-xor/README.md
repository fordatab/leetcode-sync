# Find The Original Array of Prefix Xor

**Difficulty:** Medium
**Tags:** bit-manipulation, prefix-xor, array, in-place

## Problem

Given an array of prefix XOR values, reconstruct the original array such that each prefix element equals the cumulative XOR of all original array elements up to that index. The array size can be up to 10^5 elements, with values ranging from 0 to 10^6.

## Approach

The solution exploits the property that XOR is its own inverse: if `pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]`, then `arr[i] = pref[i] ^ pref[i-1]`. The code maintains a running XOR in variable `x` (initialized to 0, representing the empty prefix) and iterates through the prefix array. For each position, it computes the original value by XORing the current prefix with the previous cumulative XOR (`pref[a] ^ x`), then updates the cumulative XOR by incorporating the newly computed element. The transformation is done in-place, modifying the input array directly to save space. The first element remains unchanged since `pref[0] ^ 0 = pref[0] = arr[0]`.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-23 03:01 UTC
- Runtime: 144 ms
- Memory: 78.7 MB
- Language: C++
