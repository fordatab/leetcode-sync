# High Five

**Difficulty:** Easy
**Tags:** hash-table, heap, priority-queue, sorting

## Problem

Given a list of student scores where each entry contains a student ID and a score, compute the average of each student's top five scores using integer division. Return the results as pairs of student ID and their top-five average, sorted by ID in ascending order. Each student is guaranteed to have at least five scores.

## Approach

The solution uses a hash map where each student ID maps to a min-heap (priority queue with smallest element at top) that maintains exactly five scores. As we iterate through all score entries, for each student we push the score onto their heap. Whenever a heap exceeds five elements, we remove the smallest score, ensuring we keep only the top five. After processing all scores, we iterate through the map to calculate each student's average by summing all elements in their heap and dividing by 5. Finally, we sort the result array by student ID before returning it.

## Complexity

- **Time:** O(n log 5 + k log k)
- **Space:** O(k)

## Stats

- Submitted: 2026-04-21 07:53 UTC
- Runtime: 0 ms
- Memory: 14.6 MB
- Language: C++
