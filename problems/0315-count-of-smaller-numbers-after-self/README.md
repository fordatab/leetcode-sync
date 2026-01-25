# Count of Smaller Numbers After Self

**Difficulty:** Hard
**Tags:** merge-sort, divide-and-conquer, array, sorting, inversions

## Problem

Given an array of integers, compute for each position how many elements to its right have smaller values. The array can contain up to 100,000 elements with values ranging from -10,000 to 10,000. Return an array where each entry represents the count of smaller elements that appear after the corresponding position in the input.

## Approach

The solution uses a modified merge sort algorithm to count inversions. Each element is paired with its original index to track positions through the sorting process.

During the merge step, when merging two sorted halves, the algorithm maintains a count of elements from the right half that have been processed. When an element from the left half is selected for merging, it means all previously selected elements from the right half are smaller and appear to its right in the original array, so this count is added to the answer for that element's original index.

The key insight is that merge sort naturally compares elements in a way that reveals how many smaller elements appear to the right: during merging, if we pick from the left subarray, we know exactly how many elements from the right subarray (which represents positions originally to the right) have already been placed and are smaller.

The recursion proceeds by splitting the array in half, recursively sorting and counting in each half, then merging while accumulating the cross-half inversions. The pair structure preserves original indices so counts can be recorded in the correct positions of the answer array.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2026-01-25 09:31 UTC
- Runtime: 986 ms
- Memory: 509.6 MB
- Language: C++
