# Number of Recent Calls

**Difficulty:** Easy
**Tags:** queue, sliding-window, design, data-stream

## Problem

Design a class that tracks the count of requests within a sliding 3000-millisecond time window. Each ping operation receives a strictly increasing timestamp and must return how many requests (including the current one) fall within the range [t - 3000, t]. The timestamps can reach up to 10^9 and there will be at most 10^4 ping calls.

## Approach

The solution uses a queue to maintain all request timestamps in chronological order. When a new ping arrives at time `t`, the code first removes all timestamps from the front of the queue that fall outside the 3000-millisecond window (those where `t - 3000 > timestamp`). This cleanup step uses a while loop that continues popping elements while the queue is non-empty and the front element is too old. After removing stale timestamps, the new timestamp `t` is added to the back of the queue. The size of the queue then represents the count of valid requests in the current window, which is returned as the result.

## Complexity

- **Time:** O(1)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-23 00:12 UTC
- Runtime: 109 ms
- Memory: 62.5 MB
- Language: C++
