# Web Crawler Multithreaded

**Difficulty:** Medium
**Tags:** multithreading, breadth-first-search, hash-table, concurrency, condition-variable

## Problem

Build a multithreaded web crawler that starts from a given URL and discovers all pages sharing the same hostname. The crawler must call an HTML parser interface to fetch links, avoid revisiting URLs, and filter out links from different hostnames. The parser's blocking call takes up to 15ms, making parallelization essential for acceptable performance with up to 1000 URLs.

## Approach

This solution uses a thread pool pattern with worker threads that process URLs from a shared queue. The main thread extracts the target hostname, initializes a work queue with the starting URL, and spawns worker threads equal to the hardware concurrency level.

Each worker thread runs a loop that waits on a condition variable until tasks are available or crawling completes. When a task is dequeued, the thread increments a "working" counter, releases the lock, calls the parser (which may block for up to 15ms), then reacquires the lock to add newly discovered URLs to the queue after filtering by hostname and deduplication via a seen set.

The termination logic checks if both the working counter is zero (no threads processing) and the queue is empty after completing a task. When this condition is met, the `done` flag is set and all threads are notified. The condition variable coordinates thread wake-ups when new work arrives or termination occurs.

A mutex protects all shared state (queue, seen set, working counter, done flag), and the lock is strategically released during the blocking parser call to maximize parallelism. After all worker threads join, the seen set contents are returned as the result.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2025-11-29 10:48 UTC
- Runtime: 68 ms
- Memory: 38.6 MB
- Language: C++
