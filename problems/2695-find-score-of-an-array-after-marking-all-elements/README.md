# Find Score of an Array After Marking All Elements

**Difficulty:** Medium
**Tags:** greedy, array, simulation, two-pointers

## Problem

Given an array of positive integers, repeatedly select the smallest unmarked element (breaking ties by choosing the leftmost), add it to a running score, mark that element and its immediate neighbors, and continue until all elements are marked. The goal is to compute the final score after all elements have been processed. The array can contain up to 100,000 elements with values up to one million.

## Approach

This solution exploits a key observation: when traversing left-to-right, we can identify contiguous "valleys" where elements form a decreasing sequence. Within each valley, the optimal marking pattern alternates positions starting from the rightmost (lowest) element.

The algorithm scans the array with a variable step size. At each position `i`, it extends forward while the next element is smaller than the current one, identifying the end of a decreasing subsequence. Once the valley endpoint is found, it walks backward from that point in steps of 2, accumulating the values at those positions into the score.

After processing a valley, the outer loop advances by 2 positions (accounting for the marked element and its right neighbor), ensuring that marked positions are naturally skipped. This greedy approach works because in any decreasing sequence, the rightmost element will be chosen first (being smallest), then its left neighbor becomes inaccessible, then the element two positions left is the next viable choice, and so on.

The solution requires no explicit marking array or priority queue—the increasing step pattern and valley detection implicitly handle the marking logic, making it both space-efficient and fast.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-04-21 22:56 UTC
- Runtime: 4 ms
- Memory: 92.1 MB
- Language: C++
