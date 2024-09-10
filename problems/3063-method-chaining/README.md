# Method Chaining

**Difficulty:** Easy
**Tags:** dataframe, filtering, sorting, method-chaining

## Problem

Given a DataFrame of animals with columns for name, species, age, and weight, identify all animals weighing more than 100 kilograms. The result should contain only the animal names, sorted by weight in descending order. The challenge specifically asks for a solution using pandas method chaining in a single line.

## Approach

The solution chains three pandas operations in a single expression:

1. **Filtering**: Uses boolean indexing `animals['weight'] > 100` to select only rows where the weight column exceeds 100
2. **Sorting**: Applies `sort_values(['weight'], ascending=False)` to order the filtered results by weight in descending order
3. **Column selection**: Uses double-bracket indexing `[['name']]` to extract only the name column while maintaining DataFrame format

This approach directly implements the method chaining requirement by avoiding intermediate variables and performing all transformations in a single return statement.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-10 07:04 UTC
- Runtime: 429 ms
- Memory: 69.4 MB
- Language: Pandas
