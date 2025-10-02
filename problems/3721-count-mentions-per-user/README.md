# Count Mentions Per User

**Difficulty:** Medium
**Tags:** simulation, sorting, string-parsing, event-processing

## Problem

Given a number of users and a list of events (either MESSAGE or OFFLINE), count how many times each user is mentioned across all MESSAGE events. Users start online; an OFFLINE event marks a user offline for exactly 60 time units. MESSAGE events can mention specific user IDs (possibly duplicated), all users ("ALL"), or all currently online users ("HERE"). Events at the same timestamp must process OFFLINE events before MESSAGE events.

## Approach

The solution first parses each event into a tuple of (timestamp, event_type, payload). It then sorts all events by timestamp, with OFFLINE events prioritized before MESSAGE events at the same timestamp using a custom rank function. A vector tracks each user's offline_until time (initially 0, meaning online). For each event, if it's OFFLINE, the code updates that user's offline_until to current_time + 60. If it's MESSAGE with "ALL", every user's mention count increments. If "HERE", only users whose offline_until is at or before the current time (i.e., online users) are incremented. Otherwise, the payload is tokenized by whitespace, each token is parsed to extract a user ID, and that user's mention count increments (allowing duplicates to count separately).

## Complexity

- **Time:** O(n log n + n*m)
- **Space:** O(n + numberOfUsers)

## Stats

- Submitted: 2025-10-02 10:17 UTC
- Runtime: 11 ms
- Memory: 45 MB
- Language: C++
