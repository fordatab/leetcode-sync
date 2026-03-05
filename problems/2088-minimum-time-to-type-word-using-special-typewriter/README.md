# Minimum Time to Type Word Using Special Typewriter

**Difficulty:** Easy
**Tags:** greedy, string, simulation

## Problem

Given a circular typewriter with letters 'a' through 'z' arranged in a circle and a pointer initially at 'a', find the minimum time in seconds to type a given word. Each second allows either moving the pointer one position clockwise or counterclockwise, or typing the current character. The word length is at most 100 characters.

## Approach

The solution iterates through each character in the target word, tracking the current pointer position (starting at 'a'). For each character:

- Add 1 second for typing the character itself
- Calculate the absolute difference between the current and previous character positions
- Choose the shorter path around the circle: either the direct distance or going the opposite direction (26 - distance)
- Add this minimum distance to the total time
- Update the previous position to the current character

This greedy approach works because each character can be reached optimally by choosing the shorter of the two possible circular paths from the previous position.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-03-05 01:58 UTC
- Runtime: 22 ms
- Memory: 8.2 MB
- Language: C++
