# Count Asterisks

**Difficulty:** Easy
**Tags:** string, simulation, state-machine

## Problem

Given a string containing letters, asterisks, and vertical bars, count the asterisks that appear outside of paired vertical bars. Vertical bars are paired consecutively (1st with 2nd, 3rd with 4th, etc.), and the string is guaranteed to have an even number of bars. Any asterisks between a pair of bars should be excluded from the count.

## Approach

The solution uses a single-pass scan with a boolean flag to track whether we're currently inside or outside a pair of vertical bars. Initially, the flag `pair` is false, indicating we're outside any pair. As we iterate through each character:

- When encountering a '|' while `pair` is false, we set `pair` to true (entering a paired region)
- When encountering a '|' while `pair` is true, we set `pair` to false (exiting a paired region)
- When encountering a '*' while `pair` is false, we increment the counter

This effectively toggles the state each time a vertical bar is found, ensuring asterisks are only counted when outside paired regions. The approach works because vertical bars always come in pairs, so the toggle mechanism correctly tracks the inside/outside state.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-24 08:45 UTC
- Runtime: 4 ms
- Memory: 8 MB
- Language: C++
