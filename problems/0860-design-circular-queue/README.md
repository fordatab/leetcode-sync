# Design Circular Queue

**Difficulty:** Medium
**Tags:** array, queue, circular-buffer, design

## Problem

Implement a circular queue data structure that supports FIFO operations with a fixed capacity. The queue should wrap around when it reaches the end of the underlying storage, allowing reuse of space freed by dequeued elements. The implementation must support enqueueing and dequeueing elements, accessing front and rear elements, and checking whether the queue is empty or full, all without using built-in queue libraries. The capacity ranges from 1 to 1000, and up to 3000 operations may be performed.

## Approach

The solution uses a fixed-size vector as the underlying storage, along with three state variables to manage the circular behavior:

- **`headIdx`** tracks the index of the front element
- **`ct`** (count) tracks how many elements are currently in the queue
- **`capacity`** stores the maximum queue size

When enqueueing, the new element is placed at position `(headIdx + ct) % capacity`, which wraps around to the beginning of the vector when necessary. The count is then incremented. When dequeueing, the head index advances by one position (with modulo wrapping) and the count decreases. The front element is simply at `headIdx`, while the rear element is at `(headIdx + ct - 1) % capacity`. Empty and full conditions are determined by comparing the count to zero and capacity respectively. This approach avoids the need to track a separate tail pointer by computing tail position from head and count.

## Complexity

- **Time:** O(1)
- **Space:** O(k)

## Stats

- Submitted: 2025-12-04 07:35 UTC
- Runtime: 7 ms
- Memory: 23.7 MB
- Language: C++
