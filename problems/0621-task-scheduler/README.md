# Task Scheduler

**Difficulty:** Medium
**Tags:** greedy, heap, priority-queue, queue, simulation, scheduling

## Problem

Given an array of tasks (labeled A-Z) and a cooldown period n, schedule all tasks such that identical tasks are separated by at least n intervals. Each interval can execute one task or be idle. The goal is to find the minimum total number of intervals needed to complete all tasks, where tasks can be executed in any order as long as the cooldown constraint is respected.

## Approach

The solution uses a greedy scheduling approach with a max-heap and a waiting queue.

- First, it counts the frequency of each task type (26 letters) and pushes all non-zero frequencies into a max-heap (priority queue).

- The main loop simulates each time interval: at each step, it checks if any tasks in the waiting queue have finished their cooldown period (tracked by time stamps) and moves them back to the max-heap.

- If the max-heap has available tasks, it pops the most frequent one, executes it (incrementing time), and if that task still has remaining instances, adds it to the waiting queue with a timestamp indicating when it can be executed again (current time + n + 1).

- If no tasks are available in the max-heap but the waiting queue isn't empty, the CPU idles (time still increments). The process continues until both the heap and queue are empty, returning the total time elapsed.

## Complexity

- **Time:** O(m * log k)
- **Space:** O(k)

## Stats

- Submitted: 2024-07-19 08:33 UTC
- Runtime: 331 ms
- Memory: 41.9 MB
- Language: C++
