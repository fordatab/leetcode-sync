# Jump Game VII

**Difficulty:** Medium
**Tags:** dynamic-programming, sliding-window, greedy, array

## Problem

Given a binary string where you start at index 0 (guaranteed to be '0'), determine if you can reach the last index. From any position i, you can jump to position j if j is within the range [i + minJump, i + maxJump] and s[j] equals '0'. The string length can be up to 100,000, making efficient tracking of reachable positions essential.

## Approach

The solution uses dynamic programming with a sliding window optimization. It maintains a boolean array `dp` where `dp[i]` indicates whether index i is reachable. The key insight is using a counter `reachable` to track how many positions in the current valid jump window can reach position i.

As we iterate through each position i, we update the `reachable` counter by:
- Incrementing when a new position enters the valid jump range (position i - minJump becomes able to reach us)
- Decrementing when a position falls out of the valid range (position i - maxJump - 1 is now too far back)

If the current position has s[i] == '0' and reachable > 0, then we can reach position i from at least one previous valid position. This sliding window approach avoids checking every position in the [minJump, maxJump] range for each i, reducing time complexity from O(n × (maxJump - minJump)) to O(n).

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2026-06-15 00:16 UTC
- Runtime: 16 ms
- Memory: 20 MB
- Language: C++
