# Time Needed to Buy Tickets

**Difficulty:** Easy
**Tags:** queue, simulation

## Problem

Given an array representing how many tickets each person in a queue wants to buy and an index k, determine how many seconds it takes for the person at position k to finish purchasing all their tickets. Each person buys one ticket per second and returns to the end of the line if they need more tickets, leaving the line once done. The array can have up to 100 people, each wanting up to 100 tickets.

## Approach

The solution simulates the queue using a standard queue data structure where each element is a pair storing the remaining tickets needed and the person's original index. It starts by enqueueing all people with their ticket counts and indices.

The main loop continues until the front person has exactly 1 ticket left and is the target person at index k. In each iteration, if the front person needs more than 1 ticket, they are re-enqueued with their ticket count decremented by 1. The front person is then removed from the queue, and the time counter increments.

Once the target person reaches the front with their last ticket, the loop exits and returns the total time plus 1 (to account for buying that final ticket). The simulation directly models the queue behavior described in the problem.

## Complexity

- **Time:** O(n * m)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-19 06:59 UTC
- Runtime: 4 ms
- Memory: 11.7 MB
- Language: C++
