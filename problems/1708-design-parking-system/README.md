# Design Parking System

**Difficulty:** Easy
**Tags:** design, simulation, counting

## Problem

Design a parking system that tracks available slots for three car sizes: big, medium, and small. The system must initialize with a fixed capacity for each size and provide a method to park cars, returning true if a slot of the matching type is available (and decrementing the count), or false if that size is full. Each car type is represented by an integer (1 for big, 2 for medium, 3 for small), and at most 1000 operations will be performed.

## Approach

The solution uses three integer member variables (`big`, `med`, `sma`) to track the remaining slots for each parking space size. During initialization, these counters are set to the provided capacities.

The `addCar` method uses a series of conditional checks to determine the car type. For type 1 (big), it checks if `big` is zero; if so, returns false (no space available). Otherwise, it decrements `big` and returns true. The same logic applies to type 2 (medium) with the `med` counter.

For type 3 (small), which is handled by the final condition (after types 1 and 2 are ruled out), it similarly checks `sma` for availability, decrements if possible, and returns the appropriate boolean. This straightforward approach directly maps car types to their respective counters without using additional data structures.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-26 02:05 UTC
- Runtime: 40 ms
- Memory: 37.1 MB
- Language: C++
