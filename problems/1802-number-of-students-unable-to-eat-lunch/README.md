# Number of Students Unable to Eat Lunch

**Difficulty:** Easy
**Tags:** queue, simulation, array

## Problem

Given two arrays representing student sandwich preferences and a stack of sandwiches (both containing only values 0 or 1), simulate a cafeteria queue where students take the top sandwich if it matches their preference, or move to the back of the queue otherwise. The process continues until no student in the queue wants the current top sandwich. Return the count of students who remain unable to eat.

## Approach

The solution simulates the queue process directly using a C++ `queue` data structure. It initializes a queue with all student preferences and uses an index `i` to track the current sandwich on top of the stack.

The algorithm runs in rounds: in each round, it processes every student currently in the queue exactly once. For each student at the front, if their preference matches the current sandwich (`sandwiches[i]`), they take it (pop from queue, increment `i`, set `take = true`). Otherwise, they move to the back (push then pop).

The key insight is tracking whether any student took a sandwich in the current round using the `take` flag. If an entire round completes without anyone taking a sandwich, the simulation stops because the remaining students will never be satisfied. The number of students left in the queue is the answer.

## Complexity

- **Time:** O(n^2)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-19 06:48 UTC
- Runtime: 0 ms
- Memory: 11.2 MB
- Language: C++
