# Text Justification

**Difficulty:** Hard
**Tags:** array, string, greedy, simulation

## Problem

Given an array of words and a target line width, format them into fully-justified text where each line is exactly the specified width. Words are greedily packed into lines, with spaces distributed evenly between words (favoring left slots when uneven). The last line and single-word lines use left-justification instead.

## Approach

The solution processes words sequentially in a greedy manner. For each line, it starts from the current position and determines how many words fit by tracking cumulative length (words plus minimum single spaces). Once a line's words are determined, it calculates the total spaces needed and distributes them.

**Line construction logic:**
- For the last line or single-word lines: join words with single spaces and pad the remainder with trailing spaces (left-justified)
- For multi-word lines: calculate `spacesBetween` (base spaces between each pair) and `extraSpaces` (leftover spaces to distribute left-to-right). Each gap gets `spacesBetween` spaces, with the leftmost gaps receiving one additional space until `extraSpaces` is exhausted

The algorithm iterates through the word array once, building one line per iteration and advancing the position pointer to the start of the next unprocessed word.

## Complexity

- **Time:** O(n * m)
- **Space:** O(n * m)

## Stats

- Submitted: 2024-09-07 04:18 UTC
- Runtime: 4 ms
- Memory: 9.4 MB
- Language: C++
