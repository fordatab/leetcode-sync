# Maximum Sum Circular Subarray

**Difficulty:** Medium
**Tags:** array, dynamic-programming, kadanes-algorithm, prefix-sum

## Problem

Find the maximum sum of a contiguous subarray within a circular array where elements can wrap around from the end to the beginning. The array has length n (1 ≤ n ≤ 3×10⁴) with integer values ranging from -3×10⁴ to 3×10⁴. Each element can be included at most once in the subarray.

## Approach

The solution handles two cases: subarrays that don't wrap around and those that do.

**Non-wrapping case:** Apply Kadane's algorithm directly to find the maximum subarray sum in the linear array.

**Wrapping case:** The key insight is that a maximum wrapping subarray equals the total array sum minus a minimum subarray in the middle. To find this, invert all array elements (multiply by -1) and apply Kadane's algorithm again — this finds the maximum sum of inverted elements, which corresponds to the minimum sum of original elements. Add this to the total sum to get the wrapping maximum.

**Edge case:** If the wrapping result is zero, it means all elements are negative and the entire array was selected as the "minimum," which is invalid. In this case, return only the non-wrapping maximum.

The final answer is the maximum of both cases.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-03 05:42 UTC
- Runtime: 40 ms
- Memory: 42.7 MB
- Language: C++
