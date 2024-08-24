# Rank Scores

**Difficulty:** Medium
**Tags:** sql, self-join, ranking, aggregation, subquery

## Problem

Given a table of game scores with an ID and a decimal score value, compute a dense ranking where scores are ranked from highest to lowest. Ties receive the same rank, and the next rank after a tie continues consecutively without gaps (dense ranking). Return each score with its rank, ordered by score descending.

## Approach

The solution uses a self-join approach with a subquery to compute dense ranks. It creates a derived table `S2` containing all distinct scores, then for each row in the main `Scores` table, counts how many distinct scores in `S2` are greater than or equal to the current score. This count effectively gives the dense rank because:

- Scores equal to or greater than the current score represent all ranks from 1 up to and including the current score's rank
- By counting distinct scores only (via the subquery), ties are handled automatically—multiple identical scores contribute only one count
- The WHERE clause `S.Score <= S2.Score` filters to scores at or above the current row's score
- Grouping by `S.Id` ensures each original row gets its own rank calculation
- Finally, results are ordered by score descending to meet the output requirement

## Complexity

- **Time:** O(n²)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-24 04:51 UTC
- Runtime: 375 ms
- Memory: 0B
- Language: MySQL
