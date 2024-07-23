# Transpose File

**Difficulty:** Medium
**Tags:** bash, awk, string-manipulation, array

## Problem

Given a text file where each row has the same number of space-separated columns, produce output where rows and columns are swapped — the first column becomes the first row, the second column becomes the second row, and so on. Each field is separated by a single space character.

## Approach

The solution uses AWK to process the file in a single pass. For each line, it iterates through all fields (columns) and builds up strings in an array `s`, where `s[i]` accumulates all values from the i-th column across all rows. On the first row (NR == 1), each field is stored directly; for subsequent rows, each field is appended to the existing string with a space separator. After processing all input lines, the END block prints each accumulated string as a separate line, effectively transposing the matrix by converting columns into rows.

## Complexity

- **Time:** O(n × m)
- **Space:** O(n × m)

## Stats

- Submitted: 2024-07-23 22:35 UTC
- Runtime: 65 ms
- Memory: 4 MB
- Language: Bash
