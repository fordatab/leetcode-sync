# Number of Visible People in a Queue

**Difficulty:** Hard
**Tags:** stack, monotonic-stack, array

## Problem

Given an array of distinct heights representing people in a queue from left to right, determine how many people each person can see to their right. A person at index i can see person at index j (where j > i) if all people between them are shorter than both the observer and the observed person. The array can contain up to 100,000 people with heights up to 100,000.

## Approach

The solution uses a monotonic decreasing stack processed from right to left through the heights array.

For each person (processing right-to-left), we pop all shorter people from the stack since the current person can see over them. Each popped person counts as one visible person. After popping shorter people, if the stack still has elements, the top represents a taller person that the current person can also see (adding one more to the count).

The key insight is that when processing person i, the stack contains people to the right in decreasing height order. The current person can see: (1) all the shorter people we pop (they're not blocked), and (2) the first taller person remaining in the stack (which blocks the view of anyone behind it). After processing, we push the current person's height onto the stack to maintain the decreasing property.

The final position (rightmost person) always sees 0 people since no one is to their right.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2026-01-14 04:12 UTC
- Runtime: 20 ms
- Memory: 88.5 MB
- Language: C++
