# Number of Divisible Triplet Sums

**Difficulty:** Medium
**Tags:** hash-table, modular-arithmetic, counting, two-pointer

## Problem

Given an array of integers and a divisor d, count how many triplets (i, j, k) exist where i < j < k and the sum of the three elements at those indices is divisible by d. The array can have up to 1000 elements, and both element values and d can be up to 10^9.

## Approach

The solution fixes the middle element j of each triplet and then counts valid pairs of left (i < j) and right (k > j) elements. For each middle position j:

1. Build a frequency map of the remainders (mod d) of all elements to the left of j
2. For each element k to the right of j, calculate what remainder is needed from the left element to make the total sum divisible by d
3. The needed remainder is computed as `(d - (mid + nums[k]) % d) % d`, which represents the value that, when added to mid + nums[k], yields a sum divisible by d
4. Add the count of left elements with that remainder to the result

This approach avoids the O(n³) brute force by using modular arithmetic and hash maps to efficiently count valid triplets for each middle element.

## Complexity

- **Time:** O(n²)
- **Space:** O(n)

## Stats

- Submitted: 2026-02-28 11:49 UTC
- Runtime: 831 ms
- Memory: 308.4 MB
- Language: C++
