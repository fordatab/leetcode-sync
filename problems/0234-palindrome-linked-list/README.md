# Palindrome Linked List

**Difficulty:** Easy
**Tags:** linked-list, two-pointers, palindrome, in-place-reversal

## Problem

Given a singly linked list with up to 100,000 nodes containing values from 0 to 9, determine whether the sequence of node values forms a palindrome (reads the same forwards and backwards). The challenge is to accomplish this efficiently in both time and space.

## Approach

The solution uses the two-pointer technique to find the middle of the linked list, then reverses the second half and compares it with the first half.

- A fast pointer advances two steps at a time while a slow pointer advances one step, allowing the slow pointer to reach the midpoint when fast reaches the end.
- Once the middle is found, the second half of the list (starting from `slow->next`) is reversed using an iterative reversal function that reassigns next pointers.
- The original first half and the reversed second half are then traversed simultaneously, comparing corresponding node values.
- If any values differ, the function returns false; if all match, it returns true indicating a palindrome.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-24 06:43 UTC
- Runtime: 151 ms
- Memory: 116.8 MB
- Language: C++
