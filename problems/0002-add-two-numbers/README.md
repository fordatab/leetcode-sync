# Add Two Numbers

**Difficulty:** Medium
**Tags:** linked-list, math, carry-propagation

## Problem

Given two singly-linked lists where each node contains a single digit and the digits are stored in reverse order, compute their sum and return it as a new linked list in the same reverse-order format. Each list has between 1 and 100 nodes, with node values from 0 to 9, and the lists represent non-negative integers without leading zeros.

## Approach

The solution operates directly on the input linked lists rather than creating a new output list. First, it pads both lists to equal length by appending zero-valued nodes, ensuring both lists end with an extra trailing zero node to handle potential overflow carry.

Then it traverses both lists simultaneously, computing the digit-wise sum at each position. When the sum is 10 or greater, it stores the ones digit in the current node and propagates the carry by incrementing the next node's value (which is guaranteed to exist due to the padding).

After processing all digits, if the final trailing node contains zero (meaning no final carry occurred), it is removed by setting the second-to-last node's next pointer to null. The modified first input list is returned as the result.

## Complexity

- **Time:** O(max(m, n))
- **Space:** O(max(m, n))

## Stats

- Submitted: 2024-07-12 09:07 UTC
- Runtime: 28 ms
- Memory: 77 MB
- Language: C++
