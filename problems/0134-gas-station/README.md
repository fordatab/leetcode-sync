# Gas Station

**Difficulty:** Medium
**Tags:** greedy, array, single-pass

## Problem

Given n gas stations arranged in a circle with specified gas amounts and travel costs between consecutive stations, determine the starting station index that allows completing a full clockwise circuit with an initially empty tank, or return -1 if impossible. The arrays gas and cost have equal length (1 to 10^5), and a unique solution is guaranteed if one exists.

## Approach

The solution uses a greedy single-pass algorithm. First, it checks if the total gas available across all stations is less than the total cost required—if so, completing the circuit is impossible and -1 is returned immediately.

The algorithm then iterates through all stations once, maintaining a running tank balance. At each station, it adds the net gain (gas gained minus cost to next station). Whenever the tank balance becomes negative, it means starting from any station up to and including the current one won't work, so the algorithm resets the tank to zero and sets the potential starting station to the next index.

The key insight is that if a total circuit is possible (total gas ≥ total cost), and we fail to reach station x from any earlier start, then the correct starting point must be at or after station x. By the end of the loop, the last candidate starting position must be the answer, since we've already verified total feasibility.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-24 08:47 UTC
- Runtime: 108 ms
- Memory: 130.9 MB
- Language: C++
