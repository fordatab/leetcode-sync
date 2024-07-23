# Change Data Type

**Difficulty:** Easy
**Tags:** pandas, dataframe, type-conversion

## Problem

Given a DataFrame containing student records with columns for student_id, name, age, and grade, convert the grade column from float type to integer type. The grade values are stored as floats (e.g., 73.0, 87.0) and need to be converted to their integer equivalents (73, 87).

## Approach

The solution uses pandas' `astype()` method to perform type conversion. It creates a new DataFrame from the input (which is redundant since the input is already a DataFrame), then selects the 'grade' column and converts it to integer type using `astype(int)`. The conversion truncates the decimal portion of each float value, leaving only the integer part. The modified DataFrame is then returned with the grade column now having an integer data type instead of float.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-23 08:58 UTC
- Runtime: 366 ms
- Memory: 69.2 MB
- Language: Pandas
