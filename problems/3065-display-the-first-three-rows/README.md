# Display the First Three Rows

**Difficulty:** Easy
**Tags:** dataframe, pandas, slicing

## Problem

Given a pandas DataFrame containing employee information (employee_id, name, department, salary), return only the first three rows of the DataFrame. The problem tests basic DataFrame slicing operations in pandas.

## Approach

The solution uses Python's slice notation directly on the DataFrame object. By applying `employees[0:3]`, it selects rows from index 0 up to (but not including) index 3, effectively returning the first three rows. This is a straightforward application of pandas' indexing capabilities, leveraging the fact that DataFrames support slice notation similar to lists.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-11 07:58 UTC
- Runtime: 451 ms
- Memory: 66.1 MB
- Language: Pandas
