# Last Person to Fit in the Bus

**Difficulty:** Medium
**Tags:** sql, self-join, cumulative-sum, grouping, window-function-alternative

## Problem

Given a table of people waiting to board a bus in a specific order, find the name of the last person who can board before the cumulative weight exceeds 1000 kilograms. Each person boards one at a time according to their turn number, and we need to track the running total of weights as people board in sequence.

## Approach

The solution uses a self-join to calculate cumulative weights for each person's boarding position. For each row in `q1` (representing a potential last person to board), it joins with all rows in `q2` where `q2.turn <= q1.turn`, effectively gathering all people who would have boarded up to and including that person. By grouping on `q1.turn` and summing `q2.weight`, we compute the cumulative weight at each boarding position. The `HAVING` clause filters to only those positions where the total weight remains at or under 1000kg. Finally, ordering by the cumulative weight in descending order and taking the top result gives us the person at the maximum valid cumulative weight—the last person who can safely board.

## Complexity

- **Time:** O(n²)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-24 08:55 UTC
- Runtime: 2214 ms
- Memory: 0B
- Language: MySQL
