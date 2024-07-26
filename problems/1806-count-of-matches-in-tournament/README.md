# Count of Matches in Tournament

**Difficulty:** Easy
**Tags:** simulation, math, iteration

## Problem

Given n teams in a tournament, simulate rounds where even-numbered teams all pair up (n/2 matches, n/2 advance) and odd-numbered teams have one bypass while the rest pair up ((n-1)/2 matches, (n-1)/2 + 1 advance). Return the total number of matches played until one winner remains. The constraint is 1 ≤ n ≤ 200.

## Approach

The solution simulates the tournament round by round using a while loop that continues until only one team remains. In each iteration, it checks whether the current number of teams is odd or even. If odd, it calculates the number of matches as `n/2` (integer division automatically handles (n-1)/2) and adds 1 to account for the team that advances without playing. If even, it simply adds `n/2` matches. After counting matches for the round, it updates n by dividing by 2 (integer division), which gives the number of teams advancing to the next round. The accumulated match count is returned once n reaches 1.

Note: There's a bug in the odd case—the code adds `n/2 + 1` to the match count when it should add `n/2` (the number of matches). This causes an off-by-one error for odd team counts, though the code was accepted.

## Complexity

- **Time:** O(log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-26 02:14 UTC
- Runtime: 0 ms
- Memory: 7.4 MB
- Language: C++
