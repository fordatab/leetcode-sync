# Count Elements With Maximum Frequency

**Difficulty:** Easy
**Tags:** hash-table, counting, array

## Problem

Given an array of positive integers, find the total count of all elements that appear with the maximum frequency. For example, if two distinct values each appear 3 times (the highest frequency), and no other value appears more often, return 6. The array has at most 100 elements with values between 1 and 100.

## Approach

The solution uses a hash map to count the frequency of each element in the input array. First, it iterates through the array once, incrementing the count for each element in an `unordered_map`. Then it finds the maximum frequency by using `std::max_element` with a custom comparator that compares the map values (frequencies). Finally, it iterates through the map again, summing up the frequencies of all elements whose frequency equals the maximum frequency found earlier. This sum represents the total number of elements (counting duplicates) that appear with the highest frequency.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-25 04:16 UTC
- Runtime: 3 ms
- Memory: 23.3 MB
- Language: C++
