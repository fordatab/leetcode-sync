# Reshape Data: Concatenate

**Difficulty:** Easy
**Tags:** dataframe, pandas, concatenation

## Problem

Given two DataFrames with identical schemas (student_id, name, age columns), combine them by stacking all rows from the first DataFrame followed by all rows from the second DataFrame. The operation is a vertical concatenation that preserves the original row order within each DataFrame.

## Approach

The solution uses pandas' built-in `concat()` function to perform vertical concatenation. By passing a list containing both DataFrames `[df1, df2]` to `pd.concat()`, the function stacks them vertically in order, appending all rows from `df2` below all rows from `df1`. This is the standard pandas idiom for combining DataFrames along the row axis (axis=0, which is the default).

## Complexity

- **Time:** O(n + m)
- **Space:** O(n + m)

## Stats

- Submitted: 2024-07-14 06:57 UTC
- Runtime: 444 ms
- Memory: 69.6 MB
- Language: Pandas
