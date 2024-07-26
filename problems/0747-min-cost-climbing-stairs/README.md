# Min Cost Climbing Stairs

**Difficulty:** Easy
**Tags:** dynamic-programming, array, in-place

## Problem

Given an array where each element represents the cost of standing on that stair step, find the minimum total cost to reach the top (beyond the last step). You can start from either the first or second step (index 0 or 1), and from any step you can advance either one or two steps forward after paying that step's cost. The array has 2 to 1000 elements with costs ranging from 0 to 999.

## Approach

This solution uses dynamic programming with a bottom-up approach that modifies the input array in place. It works backwards from the third-to-last step to the beginning, updating each step's cost to include the minimum cost of the optimal path from that step to the top.

The algorithm iterates from index `n-3` down to `0`, and for each position `i`, it adds the smaller of the two possible next steps (`cost[i+1]` or `cost[i+2]`) to the current step's cost. This builds up the total minimum cost to reach the top starting from each position.

After processing all steps, the answer is the minimum of the updated costs at the two possible starting positions: `cost[0]` and `cost[1]`. This approach avoids allocating additional memory by reusing the input array as the DP table.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-26 09:17 UTC
- Runtime: 5 ms
- Memory: 16.6 MB
- Language: C++
