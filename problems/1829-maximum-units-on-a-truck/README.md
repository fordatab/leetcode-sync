# Maximum Units on a Truck

**Difficulty:** Easy
**Tags:** greedy, sorting, array

## Problem

Given an array of box types where each type specifies a quantity of boxes and units per box, along with a truck capacity constraint, determine the maximum total units that can be loaded onto the truck. The truck has a limit on the number of boxes (not units) it can carry, and you can select any combination of boxes as long as the total count doesn't exceed the truck's capacity.

## Approach

The solution uses a greedy strategy to maximize units by prioritizing boxes with the highest unit density. First, it sorts the `boxTypes` array in descending order based on units per box (the second element of each pair). Then it iterates through the sorted array, greedily taking as many boxes as possible from each type starting with the most valuable ones. For each box type, it calculates how many boxes can be taken (the minimum of remaining truck space and available boxes of that type), adds the corresponding units to the total, and decrements the truck capacity. The loop continues until either the truck is full or all box types have been considered.

## Complexity

- **Time:** O(n log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-15 03:18 UTC
- Runtime: 24 ms
- Memory: 19.7 MB
- Language: C++
