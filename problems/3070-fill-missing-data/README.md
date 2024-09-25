# Fill Missing Data

**Difficulty:** Easy
**Tags:** dataframe, data-cleaning, pandas

## Problem

Given a DataFrame with product information including name, quantity, and price columns, replace all missing (None/NaN) values in the quantity column with 0. The name and price columns remain unchanged, and rows with valid quantity values are preserved as-is.

## Approach

The solution uses pandas' built-in `fillna()` method to handle missing values. It directly accesses the 'quantity' column of the input DataFrame and applies `fillna(0)` to replace all NaN/None values with 0. The modified column is assigned back to the DataFrame, which is then returned. This is a straightforward application of pandas' data cleaning functionality that mutates the original DataFrame in-place before returning it.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-25 05:05 UTC
- Runtime: 568 ms
- Memory: 68.9 MB
- Language: Pandas
