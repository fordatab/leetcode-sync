# Permutations

**Difficulty:** Medium
**Tags:** backtracking, recursion, permutation, hash-set

## Problem

Given an array of distinct integers with length between 1 and 6, generate all possible permutations of those integers. The integers range from -10 to 10, are guaranteed to be unique, and the output order does not matter.

## Approach

The solution uses backtracking to generate all permutations. It starts by creating an unordered set from the input array to enable iteration over the available elements. The recursive helper function `d` builds permutations incrementally:

- The base case occurs when the current permutation (`res`) has the same size as the original set, meaning all elements have been used, at which point it's added to the output.

- For each element in the set, the algorithm checks if it's already in the current permutation by linearly scanning through `res`. If the element hasn't been used yet, it's appended to `res`, a recursive call is made to continue building the permutation, and then the element is removed (backtracked) to explore other possibilities.

- This effectively explores all n! permutations by trying each unused element at each position.

## Complexity

- **Time:** O(n! * n^2)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-22 11:10 UTC
- Runtime: 5 ms
- Memory: 9.6 MB
- Language: C++
