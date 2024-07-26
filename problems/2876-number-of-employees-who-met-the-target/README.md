# Number of Employees Who Met the Target

**Difficulty:** Easy
**Tags:** array, iteration, counting

## Problem

Given an array representing hours worked by n employees (numbered 0 to n-1) and a target threshold, count how many employees worked at least the target number of hours. The array contains non-negative integers with length between 1 and 50, and both hours and target values can be up to 10^5.

## Approach

The solution uses a fold-left operation to traverse the hours array while maintaining a running count. For each employee's hours, it checks whether they meet or exceed the target threshold using a case expression. If the condition is satisfied, the accumulator is incremented by 1; otherwise, it remains unchanged. The fold starts with an initial count of 0 and processes each element sequentially, returning the final count of employees who met the target.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-26 02:06 UTC
- Runtime: 264 ms
- Memory: 60.2 MB
- Language: Erlang
