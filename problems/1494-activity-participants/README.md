# Activity Participants

**Difficulty:** Medium
**Tags:** pandas, groupby, aggregation, filtering

## Problem

Given two tables tracking friends and their activities, find all activities that have neither the maximum nor the minimum number of participants. The Friends table contains friend-activity pairs, while the Activities table lists all possible activities. Return activity names that fall strictly between the most and least popular participation counts.

## Approach

The solution uses pandas grouping and filtering to solve this in three steps:

1. **Count participants per activity**: Groups the Friends dataframe by activity and counts the number of participants (using the 'id' column count) for each activity.

2. **Find extremes**: Uses aggregation to determine both the maximum and minimum participant counts across all activities, storing these values in a small dataframe.

3. **Filter middle values**: Excludes activities whose participant count matches either the maximum or minimum value using `isin()` with negation, then selects only the activity column for the final result.

This approach handles the case where multiple activities may share the same max or min count by filtering out all activities at those extreme levels.

## Complexity

- **Time:** O(n)
- **Space:** O(k)

## Stats

- Submitted: 2026-03-05 09:35 UTC
- Runtime: 315 ms
- Memory: 67.6 MB
- Language: Pandas
