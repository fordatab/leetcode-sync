# Count the Number of Infection Sequences

**Difficulty:** Hard
**Tags:** combinatorics, binomial-coefficients, modular-arithmetic, dynamic-programming, precomputation

## Problem

Given n people in a line and a sorted array of initially infected positions, determine how many distinct infection sequences are possible modulo 10^9+7. At each step, exactly one uninfected person adjacent to an infected person becomes infected, and the problem asks for the count of all valid orderings in which the remaining people can get infected.

## Approach

The solution precomputes factorials and their modular inverses up to 10^5 to efficiently calculate binomial coefficients. It divides the uninfected people into groups (gaps between initially infected positions, plus edges). For each internal gap of size `group` between two initially sick people, there are 2^(group-1) ways the infection can spread (choosing left or right at each step), combined with the ways to interleave this group's infections with others using binomial coefficients. The binomial coefficient C(remaining, group) represents choosing when to schedule this group's infections among all remaining slots. The final result multiplies these contributions across all gaps, handling edge groups (at positions 0 and n-1) which can only spread in one direction and thus don't get the power-of-2 multiplier.

## Complexity

- **Time:** O(n + k)
- **Space:** O(n)

## Stats

- Submitted: 2026-02-02 21:01 UTC
- Runtime: 5 ms
- Memory: 39.3 MB
- Language: C++
