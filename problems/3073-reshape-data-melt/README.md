# Reshape Data: Melt

**Difficulty:** Easy
**Tags:** dataframe, reshape, pandas, melt

## Problem

Given a DataFrame with products and their sales across four quarters stored in separate columns (quarter_1 through quarter_4), transform it from wide format to long format. Each row in the output should represent a single product-quarter combination with its corresponding sales value.

## Approach

The solution uses pandas' built-in `melt()` function to reshape the DataFrame from wide to long format. The `id_vars` parameter specifies 'product' as the identifier column that should remain unchanged, while all quarter columns become values in a new 'quarter' column. The `var_name` parameter names this new column 'quarter', and `value_name` parameter names the column containing the sales figures 'sales'. This single function call unpivots all quarter columns into rows, creating one row per product-quarter pair.

## Complexity

- **Time:** O(n * m)
- **Space:** O(n * m)

## Stats

- Submitted: 2024-08-10 21:35 UTC
- Runtime: 488 ms
- Memory: 69 MB
- Language: Pandas
