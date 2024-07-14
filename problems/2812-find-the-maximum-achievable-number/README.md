# Find the Maximum Achievable Number

**Difficulty:** Easy
**Tags:** math, greedy

## Problem

Given two integers num and t, find the maximum value x that can become equal to num after performing at most t operations. Each operation allows you to simultaneously change both x and num by 1 in any direction (increase or decrease). The constraints specify that both num and t are between 1 and 50.

## Approach

The solution recognizes a key mathematical insight: to maximize x while making it equal to num through the allowed operations, we should start with x as large as possible and then close the gap. In each operation, we can decrease x by 1 while simultaneously increasing num by 1, which reduces the distance between them by 2. Therefore, if we perform t such operations, the initial gap can be 2*t, meaning x can start at num + 2*t. After t operations of decreasing x and increasing num, both values converge to num + t. The formula directly computes this maximum starting value without simulating the operations.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-14 05:58 UTC
- Runtime: 0 ms
- Memory: 9.8 MB
- Language: C++
