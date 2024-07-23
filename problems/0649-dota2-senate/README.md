# Dota2 Senate

**Difficulty:** Medium
**Tags:** queue, simulation, greedy, two-pointers

## Problem

Given a string representing senators from two parties ('R' for Radiant, 'D' for Dire), simulate a round-based voting process where senators act in order. Each senator can ban an opposing senator from all future rounds. The process continues until only one party remains, at which point that party wins. Senators play optimally for their party, and you must determine which party declares victory.

## Approach

The solution uses a queue to simulate the sequential voting rounds. It maintains counts of active senators from each party (r_ct and d_ct) and tracks pending bans (to_pop_r and to_pop_d).

The algorithm processes senators in circular order by dequeuing and re-enqueuing them. Before processing each senator, it checks if there are pending bans for their party and removes banned senators from the queue while decrementing their party count.

When an active senator's turn arrives, they ban the next opposing senator by incrementing the appropriate ban counter (to_pop_d for Radiant senators, to_pop_r for Dire senators), then the senator is added back to the queue for the next round. This greedy approach—always banning the next opponent in line—implements the optimal strategy.

The simulation terminates when one party's count reaches zero, indicating all their senators have been banned, and the remaining party is declared the winner.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-23 04:22 UTC
- Runtime: 4 ms
- Memory: 9.9 MB
- Language: C++
