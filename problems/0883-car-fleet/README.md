# Car Fleet

**Difficulty:** Medium
**Tags:** stack, sorting, greedy, monotonic-stack

## Problem

Given n cars at various positions traveling toward a target destination, each with its own speed, determine how many car fleets will arrive at the target. Cars cannot overtake but can catch up and form fleets that travel at the speed of the slowest car. All positions are unique, speeds are positive, and there can be up to 100,000 cars with a target up to 1,000,000.

## Approach

The solution pairs each car's position with its speed and sorts them in descending order by position (closest to target first). It then uses a stack to track potential fleet leaders.

For each car from front to back, the code calculates the time it takes to reach the target. If the stack is empty, the car is pushed as a potential fleet leader. If the stack has cars, it compares the current car's arrival time with the top car's arrival time. If the current car takes longer to arrive, it cannot catch up to the fleet ahead and becomes a new fleet leader, so it's pushed onto the stack. If it arrives at the same time or earlier, it catches up and joins the existing fleet, so nothing is pushed.

The key insight is that cars are processed from front to back, and a car can only join a fleet if it arrives before or at the same time as the car(s) ahead. The final stack size represents the number of distinct fleets, as each stack entry represents a fleet that cannot be caught by cars behind it.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-06-29 08:55 UTC
- Runtime: 128 ms
- Memory: 77.7 MB
- Language: C++
