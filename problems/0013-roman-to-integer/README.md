# Roman to Integer

**Difficulty:** Easy
**Tags:** hash-table, string, greedy

## Problem

Convert a string representing a valid Roman numeral into its integer equivalent. Roman numerals use seven symbols with specific values, and typically appear in descending order from left to right. However, subtractive notation is used in six cases where a smaller symbol precedes a larger one (like IV for 4 or CM for 900). The input string has length between 1 and 15 characters and represents a value between 1 and 3999.

## Approach

The solution reverses the input string and processes it from right to left (originally left to right). It maintains a running total and tracks the largest numeral value seen so far. For each character, the code looks up its numeric value in a hash map. If the current value is greater than or equal to the largest seen, it adds the value to the total and updates the largest. If the current value is smaller than the largest (indicating subtractive notation like IV), it subtracts the value instead. This reverse traversal elegantly handles the subtractive cases because when reading right-to-left, a smaller value that should be subtracted naturally appears after its larger counterpart has already been processed.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-28 04:53 UTC
- Runtime: 8 ms
- Memory: 13 MB
- Language: C++
