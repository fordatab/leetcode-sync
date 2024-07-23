# Word Frequency

**Difficulty:** Medium
**Tags:** string-processing, sorting, hash-table, shell-scripting

## Problem

Given a text file containing only lowercase letters and spaces, count how many times each word appears and output the results sorted by frequency in descending order. Each word is separated by one or more whitespace characters, and each word's frequency is guaranteed to be unique.

## Approach

The solution uses a Unix pipeline to process the text file in stages:

1. `cat words.txt` reads the file content
2. `tr -s ' ' '\n'` replaces sequences of spaces with newlines, putting each word on its own line
3. `sort` alphabetically sorts all words, grouping identical words together
4. `uniq -c` counts consecutive duplicate lines, producing counts followed by words
5. `sort -r` sorts numerically in reverse order by the count (first column)
6. `awk '{ print $2, $1 }'` swaps the columns to print word first, then count

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-23 22:34 UTC
- Runtime: 83 ms
- Memory: 3.8 MB
- Language: Bash
