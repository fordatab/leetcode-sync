# Minimum Number of Chairs in a Waiting Room

**Difficulty:** Easy
**Tags:** simulation, greedy, string

## Problem

Given a string representing a sequence of events where 'E' denotes a person entering a waiting room and 'L' denotes a person leaving, determine the minimum number of chairs required so that every entering person has a chair available. The room starts empty, and the string represents a valid sequence (no one leaves an empty room).

## Approach

The solution tracks the current occupancy of the waiting room by maintaining a running count. It iterates through each character in the string: incrementing a counter when someone enters ('E') and decrementing it when someone leaves ('L'). Throughout this simulation, it keeps track of the maximum occupancy reached using a separate variable. This maximum value represents the minimum number of chairs needed, since that's the peak simultaneous occupancy that must be accommodated.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-11 01:46 UTC
- Runtime: 0 ms
- Memory: 8.7 MB
- Language: C++
