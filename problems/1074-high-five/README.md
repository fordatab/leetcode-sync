# High Five

**Difficulty:** Easy
**Tags:** hash-table, heap, priority-queue, sorting

## Problem

<<<<<<< HEAD
Given a list of student scores where each entry contains a student ID and a score, compute the average of each student's top five scores using integer division. Return the results as pairs of student ID and their top-five average, sorted by ID in ascending order. Each student is guaranteed to have at least five scores.

## Approach

The solution uses a hash map where each student ID maps to a min-heap (priority queue with smallest element at top) that maintains exactly five scores. As we iterate through all score entries, for each student we push the score onto their heap. Whenever a heap exceeds five elements, we remove the smallest score, ensuring we keep only the top five. After processing all scores, we iterate through the map to calculate each student's average by summing all elements in their heap and dividing by 5. Finally, we sort the result array by student ID before returning it.

## Complexity

- **Time:** O(n log 5 + k log k)
- **Space:** O(k)
=======
Given a list of student score records where each record contains a student ID and a score, compute each student's average of their top five scores using integer division. Return the results as ID-average pairs sorted by student ID in ascending order. Each student is guaranteed to have at least five scores, and there can be up to 1000 total records with student IDs ranging from 1 to 1000 and scores from 0 to 100.

## Approach

The solution uses a hash map where each key is a student ID and each value is a min-heap (priority queue with greater comparator) that maintains exactly the top 5 scores for that student.

As we iterate through the items, for each score we push it onto the corresponding student's min-heap. If the heap size exceeds 5, we pop the smallest element, ensuring only the top 5 scores remain. This min-heap approach efficiently discards lower scores as we encounter higher ones.

After processing all scores, we iterate through the hash map, summing all elements in each student's heap (which now contains exactly their top 5 scores) and computing the integer division average. These results are collected into a vector.

Finally, we sort the result vector by student ID using a lambda comparator to meet the requirement of ascending ID order in the output.

## Complexity

- **Time:** O(n log 5 + m log m)
- **Space:** O(m)
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d

## Stats

- Submitted: 2026-04-21 07:53 UTC
- Runtime: 0 ms
- Memory: 14.6 MB
- Language: C++
