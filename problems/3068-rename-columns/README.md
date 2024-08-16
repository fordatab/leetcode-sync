# Rename Columns

**Difficulty:** Easy
**Tags:** dataframe, pandas, column-manipulation

## Problem

Given a DataFrame containing student information with columns 'id', 'first', 'last', and 'age', rename these columns to 'student_id', 'first_name', 'last_name', and 'age_in_years' respectively. The data itself remains unchanged; only the column headers need to be transformed.

## Approach

The solution uses pandas' `rename()` method with a dictionary mapping to transform column names. A dictionary is passed to the `columns` parameter that maps each old column name to its new name. The `inplace=True` argument modifies the original DataFrame directly rather than creating a copy, making the operation more memory-efficient. After renaming, the modified DataFrame is returned.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-16 11:01 UTC
- Runtime: 350 ms
- Memory: 68.8 MB
- Language: Pandas
