# Minimum Number of Swaps to Make the String Balanced

**Difficulty:** Medium
**Tags:** stack, greedy, string, two-pointer

## Problem

Given a string of equal numbers of opening '[' and closing ']' brackets, determine the minimum number of swaps needed to make the string balanced. A balanced string is either empty, a concatenation of two balanced strings, or an opening bracket followed by a balanced string and a closing bracket. The string has even length n (up to 10^6), with exactly n/2 of each bracket type.

## Approach

The solution uses a stack-based approach to track unmatched closing brackets. As we scan the string left-to-right:

- When we encounter an opening bracket '[', we push it onto the stack, indicating it's available to match future closing brackets.
- When we encounter a closing bracket ']', we check if there's an unmatched opening bracket in the stack. If so, we pop it (matching the pair). If the stack is empty, this closing bracket has no opening bracket to its left, so we increment an `unbalanced` counter.

After processing the entire string, `unbalanced` represents the number of closing brackets that appear before their matching opening brackets. Each swap can fix two misplaced brackets (moving an opening bracket left and a closing bracket right), so the minimum number of swaps needed is `(unbalanced + 1) / 2`, using integer division to round up.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2026-07-14 05:40 UTC
- Runtime: 13 ms
- Memory: 36.8 MB
- Language: C++
