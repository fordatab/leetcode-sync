# Design Log Storage System

**Difficulty:** Medium
**Tags:** array, string, design, linear-scan

## Problem

Design a log storage system that stores logs with unique integer IDs and timestamps in the format Year:Month:Day:Hour:Minute:Second. The system must support adding logs and querying logs within a timestamp range at varying levels of precision (granularity). When querying, the granularity parameter determines which timestamp components to consider—for example, "Day" granularity ignores hour, minute, and second values. The constraints include at most 500 total operations, IDs from 1-500, and years from 2000-2017.

## Approach

The solution stores all logs as pairs of (timestamp string, ID) in a vector without any preprocessing or indexing.

**Storage:** Each `put` operation simply appends the timestamp-ID pair to the vector in O(1) time.

**Retrieval:** For each `retrieve` query, the code first determines how many characters of the timestamp string are relevant based on the granularity (e.g., 4 for "Year", 7 for "Month", 10 for "Day", etc.). It then truncates the start and end boundaries to this prefix length.

The retrieval process scans through all stored logs linearly, extracting the same prefix length from each log's timestamp and performing lexicographic string comparisons to check if it falls within the [start, end] range. This works because the timestamp format is zero-padded and follows Year:Month:Day:Hour:Minute:Second order, making lexicographic comparison equivalent to chronological comparison when truncated to the same precision level.

All matching log IDs are collected and returned in the order they were inserted.

## Complexity

- **Time:** O(1) for put, O(n) for retrieve where n is the number of stored logs
- **Space:** O(n) where n is the number of stored logs

## Stats

- Submitted: 2025-11-29 12:13 UTC
- Runtime: 6 ms
- Memory: 21.6 MB
- Language: C++
