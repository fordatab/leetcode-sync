# Count Number of Teams

**Difficulty:** Medium
**Tags:** array, enumeration, counting, combinatorics

## Problem

Given an array of n unique soldier ratings, count how many valid 3-soldier teams can be formed. A team at indices i < j < k is valid if the ratings are either strictly increasing (rating[i] < rating[j] < rating[k]) or strictly decreasing (rating[i] > rating[j] > rating[k]). Soldiers can belong to multiple teams, and n ranges from 3 to 1000.

## Approach

The solution uses a middle-element enumeration strategy. For each soldier at position x (excluding the first and last positions), it treats that soldier as the middle member of a potential team.

For each middle soldier, it counts:
- How many soldiers to the left have a rating less than the middle (`lt`)
- How many soldiers to the right have a rating greater than the middle (`gt`)

For ascending teams, any combination of one left-smaller and one right-larger soldier forms a valid team, contributing `lt * gt` teams.

For descending teams, it calculates:
- How many soldiers to the left are greater: `a = x - lt`
- How many soldiers to the right are smaller: `b = (total right soldiers) - gt - 1`

These contribute `a * b` descending teams. The solution sums both types across all middle positions.

## Complexity

- **Time:** O(n^2)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-29 23:54 UTC
- Runtime: 51 ms
- Memory: 11.6 MB
- Language: C++
