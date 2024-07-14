# Create a New Column

**Difficulty:** Easy
**Tags:** dataframe, pandas, vectorization, column-operation

## Problem

Given a DataFrame with employee names and salaries, create a new column called 'bonus' that contains double the value of each employee's salary. The task requires adding this computed column to the existing DataFrame and returning the result.

## Approach

The solution uses pandas' `assign()` method to create a new column in a functional style. It multiplies the entire 'salary' column by 2 using vectorized operations (`2 * employees['salary']`), which applies the doubling transformation to all rows simultaneously. The `assign()` method returns a new DataFrame with the original columns plus the newly created 'bonus' column, without modifying the input DataFrame in place.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-14 06:57 UTC
- Runtime: 436 ms
- Memory: 68.9 MB
- Language: Pandas
