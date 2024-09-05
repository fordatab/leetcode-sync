# Knight Dialer

**Difficulty:** Medium
**Tags:** dynamic-programming, graph, counting, modular-arithmetic

## Problem

Given a phone keypad (digits 0-9 arranged in a standard layout) and a chess knight that moves in L-shapes, count how many distinct n-digit phone numbers can be dialed by making n-1 valid knight moves starting from any digit. The knight follows standard chess movement rules (two squares in one direction, one square perpendicular), and the result must be returned modulo 10^9 + 7. The input n ranges from 1 to 5000.

## Approach

The solution uses dynamic programming with a 2D table where `dp[i][j]` represents the number of ways to dial an i-digit number ending at digit j.

First, the base case is initialized: for n=1, there is exactly one way to dial a 1-digit number ending at each digit (the digit itself).

For each subsequent length from 2 to n, the solution calculates how many ways we can reach each digit by summing the ways to reach all digits that can jump to the current digit via a valid knight move. The valid knight moves are hardcoded based on the phone keypad layout (e.g., from digit 0, a knight can jump to 4 or 6; from digit 1, it can jump to 6 or 8).

Each transition applies the modulo operation to prevent integer overflow. Note that digit 5 is never used in the transitions (presumably because it has no valid knight moves to/from other digits on the standard keypad layout).

Finally, the solution sums all entries in `dp[n]` to get the total count of n-digit numbers, applying modulo once more before returning.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-05 00:49 UTC
- Runtime: 64 ms
- Memory: 53.7 MB
- Language: C++
