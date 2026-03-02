# Water Bottles

**Difficulty:** Easy
**Tags:** simulation, math, greedy

## Problem

Given an initial count of full water bottles and an exchange rate, determine the maximum total bottles you can drink. After drinking a bottle it becomes empty, and you can trade a certain number of empty bottles for one new full bottle. The goal is to calculate how many bottles can be consumed through repeated drinking and exchanging.

## Approach

The solution uses a simulation approach with a while loop that continues as long as there are enough empty bottles to perform an exchange. In each iteration, it calculates how many full exchange cycles can be completed (K = numBottles / numExchange), which represents trading K groups of empty bottles for K new full bottles. It then updates the consumed count by adding the bottles drunk in those exchanges (numExchange * K), reduces the empty bottle count by the same amount, and adds the newly acquired full bottles (K) back to the inventory. The loop terminates when insufficient empty bottles remain for another exchange, and the final result includes both the bottles consumed during exchanges and any remaining bottles that couldn't be exchanged.

## Complexity

- **Time:** O(log n)
- **Space:** O(1)

## Stats

- Submitted: 2026-03-02 11:15 UTC
- Runtime: 0 ms
- Memory: 7.7 MB
- Language: C++
