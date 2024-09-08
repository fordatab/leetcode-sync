# Students and Examinations

**Difficulty:** Easy
**Tags:** sql, cross-join, left-join, aggregation, group-by

## Problem

Given three tables representing students, subjects, and exam attendance records, calculate how many times each student attended each subject's exam. The result must include every combination of student and subject, even if a student never took a particular exam (showing 0 in those cases). Results should be sorted by student ID and subject name.

## Approach

The solution uses a **CROSS JOIN** to generate all possible student-subject combinations, ensuring every student appears with every subject regardless of attendance. A subquery aggregates the Examinations table by counting occurrences of each (student_id, subject_name) pair. This aggregated data is then **LEFT JOIN**ed to the cross product using both student_id and subject_name. The COALESCE function handles cases where a student never attended a particular subject's exam by replacing NULL counts with 0. Finally, the results are sorted by student_id and subject_name as required.

## Complexity

- **Time:** O(s * sub + e)
- **Space:** O(e)

## Stats

- Submitted: 2024-09-08 05:46 UTC
- Runtime: 811 ms
- Memory: 0B
- Language: MySQL
