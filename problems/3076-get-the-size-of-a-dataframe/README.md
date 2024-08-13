# Get the Size of a DataFrame

**Difficulty:** Easy
**Tags:** pandas, dataframe

## Problem

Given a pandas DataFrame containing player information with columns like player_id, name, age, position, and team, return a list with two integers: the total number of rows and the total number of columns in the DataFrame.

## Approach

The solution uses pandas DataFrame's built-in `shape` attribute, which returns a tuple containing the dimensions of the DataFrame. The first element (`shape[0]`) represents the number of rows, and the second element (`shape[1]`) represents the number of columns. These values are extracted via indexing and returned as a list. Alternatively, the entire `shape` tuple can be converted directly to a list using the `list()` constructor.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-13 23:22 UTC
- Runtime: 338 ms
- Memory: 68.7 MB
- Language: Pandas
