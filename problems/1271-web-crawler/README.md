# Web Crawler

**Difficulty:** Medium
**Tags:** depth-first-search, graph-traversal, hash-table, string-parsing

## Problem

Given a starting URL and an HTML parser interface, crawl all URLs reachable from the start that share the same hostname. The parser provides a method to fetch all links from a given URL. You must avoid revisiting URLs and only explore those with matching hostnames (the domain between 'http://' and the next slash or end of string). Return all discovered URLs in any order.

## Approach

The solution uses depth-first search (DFS) to traverse the web graph. It extracts the hostname from the starting URL by finding the substring between 'http://' (position 7) and the next forward slash. A hash set tracks visited URLs to prevent cycles and duplicate work.

The DFS function first attempts to insert the current URL into the visited set; if it's already present, the function returns immediately. Otherwise, it calls the parser to get all outgoing links from the current page. For each link, it extracts the hostname and compares it to the target hostname. Only links with matching hostnames trigger recursive DFS calls.

The crawl method initializes the visited set, extracts the target hostname, launches the DFS traversal from the starting URL, and converts the visited set into a vector for the final result.

## Complexity

- **Time:** O(V + E)
- **Space:** O(V)

## Stats

- Submitted: 2025-11-29 10:38 UTC
- Runtime: 69 ms
- Memory: 37.2 MB
- Language: C++
