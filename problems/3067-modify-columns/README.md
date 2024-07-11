# Modify Columns

**Difficulty:** Easy
**Tags:** dataframe, pandas, vectorization, in-place-modification

## Problem

Given a DataFrame with employee names and salaries, multiply each employee's salary by 2 and return the modified DataFrame. The DataFrame has two columns: 'name' (object type) and 'salary' (integer type).

## Approach

The solution directly modifies the 'salary' column in-place using pandas' vectorized multiplication operator. By accessing `employees.salary` and multiplying it by 2 with the `*=` operator, all salary values in the column are doubled simultaneously. The modified DataFrame is then returned. This approach leverages pandas' native vectorization, which applies the multiplication operation to every element in the salary column without explicit iteration.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-11 07:59 UTC
- Runtime: 379 ms
- Memory: 65.7 MB
- Language: Pandas
