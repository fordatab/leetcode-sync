# Drop Missing Data

**Difficulty:** Easy
**Tags:** dataframe, pandas, data-cleaning, filtering

## Problem

Given a DataFrame containing student records with columns for student_id, name, and age, remove all rows where the name column contains missing (null/None) values. The task is to filter out incomplete student records and return only those with valid names.

## Approach

The solution uses pandas' `notnull()` method to create a boolean mask identifying rows where the name column has non-null values. This mask is then used to filter the original DataFrame using boolean indexing, effectively keeping only rows with valid names. The DataFrame is wrapped in an additional `pd.DataFrame()` constructor call (though this is redundant since `students` is already a DataFrame) before applying the filter.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-25 05:06 UTC
- Runtime: 397 ms
- Memory: 69.4 MB
- Language: Pandas
