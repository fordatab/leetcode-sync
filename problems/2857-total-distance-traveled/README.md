# Total Distance Traveled

**Difficulty:** Easy
**Tags:** simulation, greedy

## Problem

Given a truck with two fuel tanks, calculate the maximum distance it can travel where the main tank powers the truck at 10 km per liter. Every time exactly 5 liters are consumed from the main tank, 1 liter is transferred from the additional tank to the main tank if available. The input guarantees both tanks contain 1-100 liters initially.

## Approach

The solution uses a simulation approach with a while loop that continues until the main tank is empty. In each iteration, it checks if the main tank has at least 5 liters and the additional tank has fuel available. If both conditions are met, it consumes 5 liters from the main tank (adding 50 km to the distance), then immediately transfers 1 liter from the additional tank back to the main tank. If either condition fails (main tank has fewer than 5 liters or additional tank is empty), it consumes all remaining fuel in the main tank and terminates. The distance is accumulated by multiplying liters consumed by 10 km/liter.

## Complexity

- **Time:** O(mainTank)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-28 09:22 UTC
- Runtime: 58 ms
- Memory: 10.4 MB
- Language: C++
