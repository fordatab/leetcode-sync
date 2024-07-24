# Design Twitter

**Difficulty:** Medium
**Tags:** heap, priority-queue, hash-table, design, merge-k-sorted-lists

## Problem

Design a system that allows users to post tweets, follow and unfollow other users, and retrieve their news feed. The news feed must contain the 10 most recent tweets from the user themselves and all users they follow, sorted from newest to oldest. Each user can have up to 500 different IDs, and the system must handle up to 30,000 total operations across posting, following, unfollowing, and feed retrieval.

## Approach

The solution maintains two hash maps: one storing each user's tweets as a list of [timestamp, tweetId] pairs, and another storing each user's set of followees. A global counter assigns monotonically increasing timestamps to tweets as they're posted.

When retrieving a news feed, the algorithm uses a max-heap to merge tweets from multiple users. It initializes the heap with the most recent tweet from each relevant user (the requester plus all followees). The heap stores 4-element vectors: [timestamp, tweetId, userId, index], where index tracks position in that user's tweet list.

The algorithm repeatedly extracts the tweet with the highest timestamp from the heap, adds its tweetId to the result, and pushes the next older tweet from that same user into the heap. This continues until 10 tweets are collected or the heap is empty, effectively performing a k-way merge of sorted lists.

Follow and unfollow operations simply add or remove entries from the followee set. The user is temporarily added to their own followee set during feed retrieval to include their own tweets.

## Complexity

- **Time:** O(n log k)
- **Space:** O(u + t)

## Stats

- Submitted: 2024-07-24 02:43 UTC
- Runtime: 0 ms
- Memory: 9.3 MB
- Language: C++
