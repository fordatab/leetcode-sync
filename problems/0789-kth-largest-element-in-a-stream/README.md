# Kth Largest Element in a Stream

**Difficulty:** Easy
**Tags:** heap, priority-queue, min-heap, data-structure-design, streaming-data

## Problem

Design a class that maintains a stream of test scores and efficiently returns the kth largest score after each new score is added. The class must support initialization with k and an initial array of scores, and provide an add method that inserts a new score and returns the current kth largest element. Up to 10,000 scores may be added, with values ranging from -10,000 to 10,000.

## Approach

The solution uses a min-heap (priority queue with greater comparator) of size k to track the k largest elements seen so far. The key insight is that the root of a size-k min-heap always contains the kth largest element.

During initialization, all initial scores are added to a temporary min-heap, then elements are popped until only k elements remain, ensuring we keep the k largest values. This filtered heap is stored as the instance variable.

When adding a new score, it's pushed onto the min-heap. If the heap size exceeds k, the smallest element (the root) is removed. This maintains the invariant that the heap contains exactly the k largest elements, with the kth largest at the top. The method returns this top element.

## Complexity

- **Time:** O(n log n) for initialization where n is the size of nums, O(log k) for each add operation
- **Space:** O(k)

## Stats

- Submitted: 2024-07-18 08:06 UTC
- Runtime: 30 ms
- Memory: 24.9 MB
- Language: C++
