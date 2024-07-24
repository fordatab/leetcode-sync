# Destroying Asteroids

**Difficulty:** Medium
**Tags:** greedy, sorting, simulation

## Problem

Given a planet with an initial mass and an array of asteroid masses, determine whether the planet can destroy all asteroids by colliding with them in any order. The planet destroys an asteroid if its current mass is greater than or equal to the asteroid's mass, gaining that asteroid's mass in the process. If the planet encounters an asteroid with greater mass, it is destroyed instead. The goal is to find if there exists any collision order that allows the planet to destroy every asteroid.

## Approach

The solution uses a greedy approach: sort all asteroids by mass in ascending order, then attempt to destroy them from smallest to largest. The key insight is that if we can destroy all asteroids, the optimal strategy is always to tackle the smallest available asteroid first, maximizing our chances of building up enough mass for larger ones.

The algorithm maintains a running total of the planet's mass (using `long long` to prevent overflow since the sum could exceed integer limits). It iterates through the sorted asteroids sequentially. For each asteroid, if the current planet mass is sufficient (greater than or equal to the asteroid's mass), the planet absorbs it and gains its mass. If at any point the planet encounters an asteroid it cannot destroy, the function immediately returns false.

If the loop completes without returning false, all asteroids were successfully destroyed in ascending order, so the function returns true.

## Complexity

- **Time:** O(n log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-24 08:42 UTC
- Runtime: 149 ms
- Memory: 106.8 MB
- Language: C++
