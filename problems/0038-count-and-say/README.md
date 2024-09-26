# Count and Say

**Difficulty:** Medium
**Tags:** string, simulation, run-length-encoding, iteration

## Problem

Generate the nth term in a sequence where each term is derived by performing run-length encoding on the previous term. The sequence starts with "1", and each subsequent term describes the count and digit of consecutive runs in the prior term (e.g., "1" becomes "11" meaning "one 1", which becomes "21" meaning "two 1s"). The input n is constrained between 1 and 30.

## Approach

The solution uses an iterative approach, building each term from the previous one. Starting with "1", it iterates n-1 times to generate successive terms.

For each iteration, the code appends a sentinel character 'e' to mark the end of the current string. It then scans through the string character by character, counting consecutive identical digits. When a run of identical characters is detected, it accumulates the count in variable `l` and advances the index `i`. Once the run ends (either by encountering a different character or the sentinel), it appends the count and the character to a temporary result string.

The inner while loop increments both the counter `l` and index `i` as long as consecutive characters match, stopping when it hits a different character or the sentinel 'e'. After processing all runs, the temporary string becomes the new base for the next iteration.

The sentinel character technique helps avoid boundary checking issues when looking ahead at `start[i+1]`, though the logic could be simplified. The solution correctly handles the base case when n=1 by returning "1" directly (the loop doesn't execute).

## Complexity

- **Time:** O(n * m)
- **Space:** O(m)

## Stats

- Submitted: 2024-09-26 01:02 UTC
- Runtime: 32 ms
- Memory: 10.4 MB
- Language: C++
