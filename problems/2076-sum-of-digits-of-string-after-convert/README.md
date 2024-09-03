# Sum of Digits of String After Convert

**Difficulty:** Easy
**Tags:** string, math, simulation, digit-manipulation

## Problem

Given a string of lowercase letters and an integer k, convert each letter to its alphabetic position (a=1, b=2, ..., z=26), concatenate these numbers, then repeatedly sum the digits of the result k times. The string length is at most 100 and k is at most 10.

## Approach

The solution optimizes the initial conversion step by directly summing the digits of each letter's position value instead of forming the full concatenated number. For each character, it calculates the position (c - 'a' + 1), then immediately extracts both the ones digit (using modulo 10) and tens digit (using division by 10) and adds them to the running sum. This produces the same result as the first transformation step on the concatenated number.

After the initial conversion-plus-first-transform, the code performs k-1 additional digit-sum transformations. Each transformation extracts digits from the current number using modulo and division operations, accumulating them into a new sum, then replaces the old number with this sum.

The key optimization is recognizing that converting letters to positions and then summing those digits can be done in one pass, effectively combining the conversion step with the first of the k transformations.

## Complexity

- **Time:** O(n + k log m)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-03 04:43 UTC
- Runtime: 0 ms
- Memory: 7.7 MB
- Language: C++
