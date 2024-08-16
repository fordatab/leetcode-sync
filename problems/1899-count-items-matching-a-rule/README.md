# Count Items Matching a Rule

**Difficulty:** Easy
**Tags:** array, string, iteration

## Problem

Given a list of items where each item has three attributes (type, color, name) stored as a triple, count how many items match a specified rule. The rule consists of a key indicating which attribute to check (type, color, or name) and a value to match against. The task is to return the total number of items whose selected attribute equals the given value.

## Approach

The solution iterates through each item in the input list exactly once. For each item, it uses conditional statements to determine which position in the three-element array to examine based on the `ruleKey` string. If `ruleKey` is "type", it checks index 0; if "color", index 1; otherwise ("name"), index 2. When the value at the selected index matches `ruleValue`, the counter is incremented by 1 (using the implicit boolean-to-int conversion). After examining all items, the accumulated count is returned.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-16 11:04 UTC
- Runtime: 71 ms
- Memory: 40.3 MB
- Language: C++
