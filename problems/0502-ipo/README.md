# IPO

**Difficulty:** Hard
**Tags:** greedy, heap, priority-queue, sorting

## Problem

Given an initial capital amount and up to k projects to complete, where each project requires a minimum capital to start and yields a certain profit, determine the maximum capital achievable. Projects can only be started if current capital meets or exceeds their required minimum, and completing a project adds its profit to the available capital. The task is to select at most k projects in an optimal order to maximize final capital, with constraints allowing up to 100,000 projects and capital values up to 1 billion.

## Approach

The solution uses a greedy approach with two data structures: a sorted list of projects and a max-heap for available profits.

First, all projects are paired with their capital requirements and profits, then sorted by capital requirement in ascending order. This allows efficient iteration through projects as capital increases.

For each of the k iterations, the algorithm scans through the sorted project list and pushes all newly affordable projects (those with capital requirement ≤ current capital) into a max-heap based on profit. The heap automatically prioritizes the most profitable available project.

In each iteration, the algorithm selects the top project from the heap (highest profit among affordable options), adds its profit to the current capital, and removes it from consideration. If no projects are affordable at any point, the loop terminates early.

This greedy strategy works because maximizing profit at each step maximizes the capital available for future projects, enabling access to more expensive (and potentially more profitable) projects sooner.

## Complexity

- **Time:** O(n log n + k log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-12 00:37 UTC
- Runtime: 224 ms
- Memory: 131.6 MB
- Language: C++
