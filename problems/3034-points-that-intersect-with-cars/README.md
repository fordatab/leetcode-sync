# Points That Intersect With Cars

**Difficulty:** Easy
**Tags:** difference-array, prefix-sum, range-query, array

## Problem

Given a list of intervals representing cars parked on a number line, where each interval is defined by a start and end position (both inclusive), count how many distinct integer positions are covered by at least one car. The coordinates range from 1 to 100, and there can be up to 100 cars.

## Approach

This solution uses a **difference array** (also known as a range update technique) to efficiently track coverage:

- Create an array of size 102 initialized to zeros
- For each car interval [start, end], increment the counter at position `start` and decrement at position `end+1`. This marks the beginning and end of each car's coverage
- Perform a prefix sum traversal from position 1 to 100. The running sum at any position indicates how many cars cover that point
- Count all positions where the running sum is greater than zero (meaning at least one car covers it)

The key insight is that instead of marking every position in each interval individually (which would be O(n*m) where m is the average interval length), the difference array lets us mark only the boundaries and derive coverage in a single linear pass.

## Complexity

- **Time:** O(n + k)
- **Space:** O(k)

## Stats

- Submitted: 2024-08-17 06:44 UTC
- Runtime: 18 ms
- Memory: 30 MB
- Language: C++
