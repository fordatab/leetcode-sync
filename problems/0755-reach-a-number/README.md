# Reach a Number

**Difficulty:** Medium
**Tags:** math, greedy, number-theory

## Problem

Starting at position 0 on an infinite number line, reach a target position by making moves where the i-th move covers exactly i steps in either direction (left or right). The goal is to find the minimum number of moves needed to reach the target. The target can be any integer between -10^9 and 10^9 (excluding 0).

## Approach

The solution exploits symmetry by taking the absolute value of the target, since reaching -n and +n require the same number of moves.

It incrementally accumulates steps (1 + 2 + 3 + ... + k) until the sum meets or exceeds the target. This gives us the smallest k where we could potentially reach the target if all steps went in the positive direction.

The key insight is that flipping any step i from positive to negative changes our position by -2i. So if the sum overshoots the target by a difference d, we need d to be even—then we can flip a step of size d/2 to land exactly on target. If (sum - target) is already even, return k immediately.

If not, we try k+1: adding one more step might make the new difference even. If (sum + k+1 - target) is even, return k+1.

Otherwise, we need k+2 moves. By incrementing twice, at least one of those additions will change the parity of the difference, making it even and thus reachable.

## Complexity

- **Time:** O(√target)
- **Space:** O(1)

## Stats

- Submitted: 2026-03-02 11:40 UTC
- Runtime: 0 ms
- Memory: 7.7 MB
- Language: C++
