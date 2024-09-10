# Decode XORed Array

**Difficulty:** Easy
**Tags:** bit-manipulation, xor, array

## Problem

Given an encoded array where each element is the XOR of two consecutive elements from a hidden original array, and given the first element of the original array, reconstruct the complete original array. The encoded array has length n-1 where n is the length of the original array, with encoded[i] = arr[i] XOR arr[i+1]. The array size can be up to 10^4 elements, and all values are non-negative integers up to 10^5.

## Approach

The solution exploits the property that XOR is self-inverse: if `a XOR b = c`, then `a XOR c = b`. Starting with the known first element, we initialize the result array with this value. Then we iterate through the encoded array, and for each encoded value, we XOR it with the last element we decoded to recover the next original element. Specifically, since `encoded[i] = arr[i] XOR arr[i+1]`, we can compute `arr[i+1] = arr[i] XOR encoded[i]`. We append each newly decoded value to the result array and use it to decode the next element, continuing until all elements are recovered.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-10 07:13 UTC
- Runtime: 19 ms
- Memory: 28.5 MB
- Language: C++
