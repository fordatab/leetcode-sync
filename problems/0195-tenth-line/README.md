# Tenth Line

**Difficulty:** Easy
**Tags:** text-processing, file-io, shell-scripting

## Problem

Given a text file, extract and print only the 10th line. If the file contains fewer than 10 lines, the output should be empty (nothing is printed).

## Approach

The solution uses `awk`, a text-processing tool that processes input line by line. The `NR` built-in variable in `awk` tracks the current line number being processed. The pattern `NR == 10` creates a condition that matches only when the line number equals 10. When this condition is true, `awk`'s default action is to print the entire line. For files with fewer than 10 lines, the condition never matches and nothing is output.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-23 22:35 UTC
- Runtime: 22 ms
- Memory: 3.9 MB
- Language: Bash
