# XOR Queries of a Subarray

**Difficulty:** Medium
**Tags:** prefix-sum, bit-manipulation, xor, array

## Problem

Given an array of positive integers and a list of range queries, compute the XOR of all elements within each specified range [left, right]. The array can have up to 30,000 elements, and there can be up to 30,000 queries, making a naive approach of computing XOR for each query range inefficient.

## Approach

The solution uses a prefix XOR technique to answer queries in constant time after preprocessing. The array is transformed in-place so that each element becomes the XOR of all elements from the start up to that index (arr[i] becomes arr[0] ^ arr[1] ^ ... ^ arr[i]). This preprocessing takes linear time.

For each query [left, right], the XOR of the range can be computed using the property that XOR is self-inverse: to get the XOR from left to right, we XOR the prefix up to right with the prefix up to left-1. This cancels out all elements before left, leaving only the elements in the desired range.

The code handles two cases: if left is 0, the answer is simply the prefix XOR at right (arr[right]); otherwise, it computes arr[left-1] ^ arr[right] to isolate the range [left, right]. Each query is answered in O(1) time after the O(n) preprocessing step.

## Complexity

- **Time:** O(n + q)
- **Space:** O(q)

## Stats

- Submitted: 2024-09-13 23:55 UTC
- Runtime: 75 ms
- Memory: 44.5 MB
- Language: C++
