# Patients With a Condition

**Difficulty:** Easy
**Tags:** sql, regular-expression, pattern-matching, string-matching

## Problem

Given a table of patients with a conditions column containing space-separated medical codes, find all patients who have Type I Diabetes. A condition indicates Type I Diabetes if it starts with the prefix 'DIAB1'. The conditions field may contain zero or more codes separated by spaces, and the target prefix can appear at the beginning of the string or after a space.

## Approach

The solution uses a regular expression with the `REGEXP` operator to match the pattern `\bDIAB1`. The `\b` is a word boundary anchor that ensures 'DIAB1' appears at the start of a word (either at the beginning of the string or after whitespace). This correctly identifies conditions like 'DIAB100' or 'DIAB1' while avoiding false matches where 'DIAB1' appears in the middle of a code (though the problem constraints suggest codes are space-separated, making this a non-issue). The query simply filters the entire Patients table and returns all columns for matching rows.

## Complexity

- **Time:** O(n * m)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-25 04:59 UTC
- Runtime: 642 ms
- Memory: 0B
- Language: MySQL
