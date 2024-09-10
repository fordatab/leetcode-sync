# Create a DataFrame from List

**Difficulty:** Easy
**Tags:** pandas, dataframe, data-manipulation

## Problem

Given a 2D list where each inner list contains a student ID and age, construct a pandas DataFrame with columns named 'student_id' and 'age'. The DataFrame must preserve the order of rows as they appear in the input list.

## Approach

The solution uses pandas' DataFrame constructor directly on the 2D list. By passing `student_data` as the `data` parameter and specifying the column names via the `columns` parameter, pandas automatically interprets each inner list as a row and assigns the first element to 'student_id' and the second to 'age'. This one-line approach leverages pandas' built-in capability to convert nested list structures into tabular format without any explicit iteration or manipulation.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-10 06:56 UTC
- Runtime: 370 ms
- Memory: 68.9 MB
- Language: Pandas
