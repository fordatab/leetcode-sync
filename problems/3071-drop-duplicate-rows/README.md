# Drop Duplicate Rows

**Difficulty:** Easy
**Tags:** dataframe, pandas, deduplication, data-cleaning

## Problem

Given a DataFrame containing customer information with columns for customer_id, name, and email, remove all duplicate rows that share the same email address. Only the first occurrence of each unique email should be retained in the output, preserving the original order of rows.

## Approach

The solution uses pandas' built-in `drop_duplicates()` method with the `subset` parameter set to `['email']`. This method scans through the DataFrame and identifies rows where the email column contains duplicate values. By default, `drop_duplicates()` keeps the first occurrence of each duplicate group and removes all subsequent occurrences. The `subset` parameter restricts the duplicate detection to only consider the email column, ignoring differences in customer_id or name. This single method call handles the entire deduplication process efficiently, leveraging pandas' optimized internal implementation.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-27 10:58 UTC
- Runtime: 366 ms
- Memory: 70 MB
- Language: Pandas
