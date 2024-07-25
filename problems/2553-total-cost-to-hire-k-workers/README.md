# Total Cost to Hire K Workers

**Difficulty:** Medium
**Tags:** heap, priority-queue, two-pointers, greedy

## Problem

Given an array of hiring costs and two integers k and candidates, select exactly k workers by running k hiring sessions. In each session, choose the worker with the lowest cost from either the first 'candidates' workers or the last 'candidates' workers in the remaining pool, breaking ties by selecting the smaller index. Return the total cost of hiring k workers.

## Approach

The solution uses two min-heaps to track candidates from the front and back of the array. Initially, it populates the left heap with the first 'candidates' workers and the right heap with the last 'candidates' workers, adjusting the candidate count to avoid overlap when it exceeds half the array size.

For each of the k hiring sessions, it compares the minimum values from both heaps. When the left heap's minimum is smaller or equal (to handle tie-breaking by index), it selects from the left heap and adds the next worker from the left pointer to the left heap. Otherwise, it selects from the right heap and adds the next worker from the right pointer to the right heap.

Two pointers (l and r) track the boundaries of unconsidered workers. After selecting a worker, the appropriate pointer advances inward, and a new worker is added to the corresponding heap if workers remain between the pointers. The total cost accumulates the selected worker costs across all k sessions.

## Complexity

- **Time:** O(k log candidates)
- **Space:** O(candidates)

## Stats

- Submitted: 2024-07-25 21:52 UTC
- Runtime: 379 ms
- Memory: 76.7 MB
- Language: C++
