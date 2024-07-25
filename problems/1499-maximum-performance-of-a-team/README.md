# Maximum Performance of a Team

**Difficulty:** Hard
**Tags:** greedy, heap, sorting, priority-queue

## Problem

Given n engineers with speed and efficiency values, select at most k engineers to maximize team performance, defined as the sum of selected speeds multiplied by the minimum efficiency among them. The result should be returned modulo 10^9 + 7. Constraints allow up to 100,000 engineers with speeds up to 100,000 and efficiencies up to 100,000,000.

## Approach

The solution uses a greedy approach combined with a min-heap. First, engineers are paired by their efficiency and speed, then sorted in descending order by efficiency. This ensures that as we iterate through engineers, the current engineer's efficiency becomes the minimum for any team containing them.

For each engineer considered (in efficiency-descending order), we add their speed to a min-heap and update the running sum of speeds. The heap maintains at most k engineers by evicting the one with the smallest speed when the size exceeds k. This greedy choice maximizes the speed sum for each fixed minimum efficiency.

At each step, we calculate the potential performance as the current speed sum multiplied by the current engineer's efficiency (which is guaranteed to be the minimum). We track the maximum performance seen across all iterations. The final answer is this maximum modulo 10^9 + 7.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-25 09:49 UTC
- Runtime: 66 ms
- Memory: 42.6 MB
- Language: C++
