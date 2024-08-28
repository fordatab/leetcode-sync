# Minimum Number of Pushes to Type Word I

**Difficulty:** Easy
**Tags:** greedy, sorting, frequency-counting, math

## Problem

Given a string with distinct lowercase letters, determine the minimum number of key presses needed to type it on a remappable telephone keypad. You can assign any letters to keys 2-9, and typing a letter requires a number of presses equal to its position on that key (first letter = 1 press, second = 2 presses, etc.). The goal is to find an optimal key assignment that minimizes total presses.

## Approach

The solution uses a greedy frequency-based approach:

1. **Count character frequencies**: Build a frequency array for all 26 letters, counting how many times each appears in the input word.

2. **Sort by frequency (descending)**: Sort the frequency array in reverse order so the most frequent characters come first.

3. **Assign characters to key positions**: Iterate through the sorted frequencies and assign them to keypad positions. Since there are 8 available keys (2-9), the first 8 most frequent characters get position 1 (requiring 1 press each), the next 8 get position 2 (requiring 2 presses each), and so on.

4. **Calculate total cost**: For each character frequency, multiply it by its press cost `(x/8 + 1)`, where `x` is the index in the sorted array. This formula ensures the first 8 characters cost 1 press each, characters 8-15 cost 2 presses each, etc.

The greedy strategy works because assigning the most frequent characters to positions requiring fewer presses minimizes the overall press count.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-28 09:13 UTC
- Runtime: 0 ms
- Memory: 10.6 MB
- Language: C++
