# Minimum Interval to Include Each Query

**Difficulty:** Hard
**Tags:** sorting, heap, priority-queue, sweep-line, greedy

## Problem

Given a collection of intervals (each defined by a start and end point) and a list of query points, find the size of the smallest interval that contains each query point. An interval contains a query if the query falls within its inclusive bounds. If no interval contains a query, return -1 for that query. Constraints allow up to 100,000 intervals and queries, with coordinate values up to 10^7.

## Approach

The solution uses a sweep-line algorithm combined with a min-heap to efficiently process queries in sorted order.

First, both intervals and queries are sorted—intervals by their start points, and queries by value while preserving original indices. A min-heap stores intervals by their size (with the endpoint as a tiebreaker).

For each query in ascending order, the algorithm adds all intervals whose left endpoint is at or before the current query value to the heap. Then it removes intervals from the heap whose right endpoint is before the query (meaning they don't contain this query point).

After pruning expired intervals, the top of the heap contains the smallest interval that contains the current query. The result is stored in a hash map keyed by the original query index, then reconstructed in the original query order for the final output.

## Complexity

- **Time:** O(n log n + m log m + (n + m) log n)
- **Space:** O(n + m)

## Stats

- Submitted: 2024-08-24 00:20 UTC
- Runtime: 346 ms
- Memory: 130.3 MB
- Language: C++
