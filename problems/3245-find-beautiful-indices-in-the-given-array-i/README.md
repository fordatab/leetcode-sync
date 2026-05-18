# Find Beautiful Indices in the Given Array I

**Difficulty:** Medium
**Tags:** string, string-matching, two-pointers, greedy

## Problem

Given a string s and two pattern strings a and b, along with an integer k, find all indices where pattern a occurs in s such that there exists an occurrence of pattern b within distance k from that index. Return these indices in sorted order. The string s can be up to 10^5 characters, while patterns a and b are at most 10 characters each.

## Approach

The solution uses string searching to find occurrences of pattern `a` in the input string `s`. For each occurrence of `a` at position `pos`, it searches for pattern `b` starting from position `max(0, pos - k)` to potentially find a nearby match. If a match of `b` is found at position `pos2` and the absolute distance between `pos2` and `pos` is at most `k`, then `pos` is added to the result array.

The code iterates through all occurrences of pattern `a` using `string::find()`, advancing the search position by 1 after each find. For each `a`-match, it performs a single search for `b` starting from the leftmost valid position within range.

However, this approach has a critical flaw: it only finds the *first* occurrence of `b` starting from `pos - k`, which may not satisfy the distance constraint. It doesn't check if there might be other occurrences of `b` within the valid range `[pos - k, pos + k]` if the first one found is too far away.

## Complexity

- **Time:** O(n * (m + p))
- **Space:** O(1)

## Stats

- Submitted: 2026-05-18 20:20 UTC
- Runtime: 110 ms
- Memory: 16.5 MB
- Language: C++
