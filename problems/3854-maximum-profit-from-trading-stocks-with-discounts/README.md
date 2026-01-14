# Maximum Profit from Trading Stocks with Discounts

**Difficulty:** Hard
**Tags:** tree-dp, dynamic-programming, depth-first-search, knapsack, tree

## Problem

Given a company hierarchy of n employees (each with stock buy/sell prices) and a budget, find the maximum profit from purchasing stocks. Employee 1 is the CEO and root of the tree. If an employee buys their stock, their direct subordinates can purchase at half price (floored). Each stock can be bought at most once, and all purchases must fit within the initial budget (profits cannot be reinvested). Constraints include n ≤ 160, prices ≤ 50, and budget ≤ 160.

## Approach

The solution uses **tree DP** with memoization on the company hierarchy. For each employee node, it maintains two states: whether the node buys at full price (state 0) or at discounted half-price (state 1), across all possible budget allocations.

Starting from the leaves via DFS, the algorithm computes two intermediate arrays at each node: `pwb` (profit when buying) and `pwob` (profit without buying). For each child, it performs a knapsack-style merge, trying all budget splits between the current accumulated profit and the child's subtree.

After processing all children, it calculates the final DP values for the node itself. `dp[node][budget][0]` represents max profit when the node can buy at full price (or chooses not to buy), while `dp[node][budget][1]` represents max profit when the node gets the discount. The key insight is that a child's discount availability depends on whether their parent bought stock, hence the two-state design.

The time-intensive nested loops enumerate all budget partitions across siblings in the tree, combining their contributions optimally. The final answer is `dp[1][budget][0]`, the maximum profit starting from the CEO with the full budget and no discount.

## Complexity

- **Time:** O(n * budget^2 * children_per_node)
- **Space:** O(n * budget)

## Stats

- Submitted: 2026-01-14 04:33 UTC
- Runtime: 937 ms
- Memory: 183.9 MB
- Language: C++
