# Baseball Game

**Difficulty:** Easy
**Tags:** stack, simulation, string

## Problem

Given a list of string operations representing baseball game scoring rules, maintain a record of scores. Operations include: adding an integer score, '+' to add the sum of the previous two scores, 'D' to add double the previous score, and 'C' to remove the most recent score. Return the sum of all scores in the final record. The input guarantees all operations are valid (e.g., '+' always has at least two prior scores).

## Approach

The solution uses a stack to maintain the current record of scores. It iterates through each operation:

- For 'D', it pushes double the top element onto the stack
- For '+', it temporarily pops the top element, calculates the sum with the new top, restores the popped element, then pushes the sum
- For 'C', it removes the top element
- For numeric strings, it converts them to integers and pushes them onto the stack

After processing all operations, it pops all elements from the stack while accumulating their sum, which is returned as the final answer.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-24 00:25 UTC
- Runtime: 0 ms
- Memory: 11.9 MB
- Language: C++
