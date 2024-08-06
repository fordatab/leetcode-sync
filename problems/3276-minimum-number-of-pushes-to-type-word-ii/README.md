# Minimum Number of Pushes to Type Word II

**Difficulty:** Medium
**Tags:** greedy, hash-table, sorting, frequency-counting

## Problem

Given a string of lowercase letters, determine the minimum number of key presses needed to type it on a remappable telephone keypad. You can assign any letters to keys 2-9, and each letter must be on exactly one key. The cost to type a letter is its position on that key times its frequency in the string (first letter on a key costs 1 press per occurrence, second costs 2 presses, etc.).

## Approach

The solution uses a greedy frequency-based assignment strategy:

1. **Count character frequencies**: Build a hash map counting how many times each character appears in the input word.

2. **Extract and sort frequencies**: Convert the frequency map into a vector of counts and sort them in descending order. This ensures the most frequent characters are considered first.

3. **Assign characters to key positions**: Iterate through the sorted frequencies. Since there are 8 available keys (2-9), the first 8 most frequent characters are placed as the first letter on each key (1 press each), the next 8 as the second letter on each key (2 presses each), and so on. The formula `x/8 + 1` calculates the number of presses needed based on the character's position in the sorted list.

4. **Accumulate total cost**: For each character, multiply its frequency by its assigned press count and sum these products to get the minimum total pushes.

## Complexity

- **Time:** O(n + k log k)
- **Space:** O(k)

## Stats

- Submitted: 2024-08-06 23:49 UTC
- Runtime: 123 ms
- Memory: 29.4 MB
- Language: C++
