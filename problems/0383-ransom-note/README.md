# Ransom Note

**Difficulty:** Easy
**Tags:** hash-table, string, counting

## Problem

Given two strings, determine whether the first string can be formed using characters from the second string, where each character in the second string can be used at most once. Both strings contain only lowercase English letters and can be up to 100,000 characters long.

## Approach

The solution uses a frequency-counting approach with a fixed-size array. First, it creates a vector of 26 integers (one for each lowercase letter) initialized to zero. It then iterates through the magazine string, incrementing the count for each character encountered. Next, it processes the ransom note string, decrementing the count for each character needed. Finally, it checks if any count has become negative — if so, the ransom note required more of that character than the magazine provided, so it returns false. If all counts remain non-negative, the construction is possible and it returns true.

## Complexity

- **Time:** O(n + m)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-13 22:32 UTC
- Runtime: 10 ms
- Memory: 10.4 MB
- Language: C++
