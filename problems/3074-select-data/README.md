# Select Data

**Difficulty:** Easy
**Tags:** dataframe, pandas, filtering, indexing

## Problem

Given a DataFrame containing student information with columns student_id, name, and age, extract only the name and age columns for the student whose student_id equals 101. The input DataFrame can contain multiple students, but only one row should match the given ID.

## Approach

The solution uses pandas' `loc` indexer to perform both row filtering and column selection in a single operation. First, it creates a boolean mask by comparing the 'student_id' column to 101, which identifies the matching row. Then it uses this mask as the row selector in `loc`, while simultaneously specifying `['name', 'age']` as the column selector to extract only those two columns. This returns a new DataFrame containing just the name and age of the student with ID 101.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-10 07:00 UTC
- Runtime: 376 ms
- Memory: 68.8 MB
- Language: Pandas
