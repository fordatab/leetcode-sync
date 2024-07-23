# Valid Phone Numbers

**Difficulty:** Easy
**Tags:** grep, regular-expressions, pattern-matching, bash

## Problem

Given a text file with one phone number per line, identify and print only those that match exactly one of two valid formats: either three digits, hyphen, three digits, hyphen, four digits (xxx-xxx-xxxx), or an opening parenthesis, three digits, closing parenthesis, space, three digits, hyphen, four digits ((xxx) xxx-xxxx). Each line has no leading or trailing whitespace.

## Approach

The solution uses `grep` with two regular expression patterns connected by the `-e` flag to match either valid format. The first pattern `^[0-9]\{3\}\-[0-9]\{3\}\-[0-9]\{4\}$` matches the xxx-xxx-xxxx format by anchoring to line start (`^`) and end (`$`), requiring exactly three digits, a literal hyphen (escaped as `\-`), three more digits, another hyphen, and four final digits. The second pattern `^([0-9]\{3\}) [0-9]\{3\}\-[0-9]\{4\}$` similarly matches the (xxx) xxx-xxxx format with a literal opening parenthesis, three digits, literal closing parenthesis, a space, three digits, a hyphen, and four digits. The anchors ensure the entire line matches one format exactly, with no extra characters. Lines matching either pattern are printed to stdout.

## Complexity

- **Time:** O(n * m)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-23 22:35 UTC
- Runtime: 57 ms
- Memory: 3.4 MB
- Language: Bash
