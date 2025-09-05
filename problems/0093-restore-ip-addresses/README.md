# Restore IP Addresses

**Difficulty:** Medium
**Tags:** backtracking, string, recursion, depth-first-search

## Problem

Given a string of digits, find all ways to partition it into exactly four segments where each segment represents a valid IP address octet (an integer from 0 to 255 with no leading zeros, except for the value 0 itself). The digits must be used in order without rearrangement or removal, and dots are inserted between segments to form complete IP addresses.

## Approach

The solution uses backtracking to explore all valid ways to partition the input string into four segments. Starting from index 0, it tries creating segments of length 1, 2, or 3 characters at each step. For each potential segment, it validates two conditions: it rejects segments with leading zeros (except "0" itself) and segments whose numeric value exceeds 255. When a valid segment is found, it's appended to the current IP address string (with a dot separator if not the first segment), then recursively processes the remaining characters. The recursion terminates successfully when exactly four segments have been formed and all characters have been consumed. Backtracking is implemented by recording the string size before each recursive call and resizing back to that point afterward, effectively removing the added segment and dot.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2025-09-05 11:25 UTC
- Runtime: 0 ms
- Memory: 10.9 MB
- Language: C++
