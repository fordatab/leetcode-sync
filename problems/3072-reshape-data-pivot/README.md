# Reshape Data: Pivot

**Difficulty:** Easy
**Tags:** pandas, data-reshaping, pivot-table

## Problem

Given a DataFrame containing city names, months, and temperature values, transform the data from a long format to a wide format where each row represents a month and each column represents a city's temperature for that month. The original data has one temperature reading per row, while the output should have all cities' temperatures for a given month in a single row.

## Approach

The solution uses pandas' built-in `pivot()` method to reshape the DataFrame from long to wide format. The method takes three parameters: `index='month'` specifies that months should become the row labels, `columns='city'` indicates that unique city names should become column headers, and `values='temperature'` determines which data should populate the cells. This single function call automatically handles the aggregation and restructuring, creating a pivot table where the intersection of each month-row and city-column contains the corresponding temperature value.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-25 05:05 UTC
- Runtime: 376 ms
- Memory: 70.6 MB
- Language: Pandas
