# Split Message Based on Limit

**Difficulty:** Hard
**Tags:** string, greedy, simulation, math

## Problem

Given a message string and a limit, split the message into parts where each part has a suffix "<a/b>" (a is the part index, b is total parts). Each part's total length (text + suffix) must equal the limit, except the last part which can be shorter. When suffixes are removed and parts concatenated in order, they must form the original message. Return the split parts using the minimum number of parts possible, or an empty array if impossible.

## Approach

The solution iterates through possible numbers of parts from 1 to n (message length). For each candidate part count, it calculates whether that many parts can accommodate the entire message.

For a given number of parts, the suffix "<a/b>" has a fixed digit count for b, but a varies as part indices go from 1 to parts. The code groups parts by the digit count of their index (1-digit indices, 2-digit indices, etc.) and calculates the total character capacity across all parts. For each group, it computes how many characters can be stored per part (limit minus suffix length) and multiplies by the count of parts in that group.

Once a valid part count is found where total capacity >= message length, the solution reconstructs the result by iterating through each part index, computing its suffix length, determining how many message characters fit, and building each part string with its suffix. The first valid configuration is returned since we iterate from smallest to largest part count.

## Complexity

- **Time:** O(n * log n)
- **Space:** O(n)

## Stats

- Submitted: 2025-09-05 11:04 UTC
- Runtime: 85 ms
- Memory: 44.4 MB
- Language: C++
