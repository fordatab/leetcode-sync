# Find Score of an Array After Marking All Elements

**Difficulty:** Medium
<<<<<<< HEAD
**Tags:** heap, priority-queue, hash-set, greedy, simulation

## Problem

Given an array of positive integers, repeatedly select the smallest unmarked element (breaking ties by choosing the leftmost index), add it to a running score, then mark that element and its two neighbors (if they exist). Continue until all elements are marked and return the total score. The array can contain up to 100,000 elements with values up to 1,000,000.

## Approach

The solution uses a min-heap (priority queue) to efficiently retrieve elements in ascending order by value, with index as a tiebreaker. All elements are initially inserted into the heap as (value, index) pairs. An unordered set tracks which indices have been marked.

The algorithm repeatedly extracts the minimum element from the heap. If that index is already marked, it's skipped. Otherwise, its value is added to the score, and the element itself plus its left and right neighbors (if within bounds) are added to the marked set.

The loop continues until the marked set contains all indices (size equals array length). This approach avoids repeatedly scanning the array for the next unmarked minimum, trading space for time by maintaining both the heap and the set.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2026-04-21 20:48 UTC
- Runtime: 282 ms
- Memory: 150.4 MB
=======
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
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d
- Language: C++
