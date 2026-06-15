# Jump Game VII

**Difficulty:** Medium
**Tags:** dynamic-programming, sliding-window, greedy, array

## Problem

Given a binary string and two integers minJump and maxJump, determine if you can reach the last index starting from index 0. From any position i, you can jump to position j if j is within the range [i + minJump, i + maxJump] and the character at position j is '0'. The string has length up to 10^5, and the first character is always '0'.

## Approach

This solution uses dynamic programming with a sliding window optimization. It maintains a `dp` array where `dp[i]` indicates whether position i is reachable. Additionally, it tracks a `reachable` counter that represents how many positions in the current valid jump window can reach the current position.

As we iterate through each position, we update the `reachable` counter by adding positions that newly enter the valid jump range (at distance minJump behind) and subtracting positions that fall out of range (beyond maxJump distance). A position is marked reachable if it contains '0' and there's at least one reachable position in the valid jump window (reachable > 0).

This sliding window approach avoids checking every position in the [minJump, maxJump] range individually, reducing what would be O(n × (maxJump - minJump)) time to O(n). The final answer is whether the last position is reachable.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2026-06-15 00:16 UTC
- Runtime: 16 ms
- Memory: 20 MB
- Language: C++
