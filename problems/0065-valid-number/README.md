# Valid Number

**Difficulty:** Hard
**Tags:** string, state-machine, parsing, validation

## Problem

Determine if a given string represents a valid numeric value according to specific formatting rules. A valid number can be an integer or decimal (with optional leading sign and optional decimal point) optionally followed by an exponent notation ('e' or 'E' with a signed integer). The string length is at most 20 characters and contains only letters, digits, plus, minus, and dot characters.

## Approach

The solution uses a single-pass state-tracking approach with boolean flags. It iterates through each character and maintains three flags: `seenDigit` (whether any digit has been encountered in the current section), `seenExponent` (whether 'e'/'E' has appeared), and `seenDot` (whether a decimal point has appeared).

For each character type:
- **Digits**: Simply mark that a digit has been seen
- **Signs (+/-)**: Only valid at the start or immediately after an exponent character
- **Exponent (e/E)**: Only valid if we haven't seen one before and we've seen at least one digit; resets the digit flag to ensure the exponent part contains digits
- **Dot**: Only valid if we haven't seen a dot or exponent yet
- **Other characters**: Immediately invalidate the string

The final check ensures at least one digit was seen in the last section (after any exponent), guaranteeing the number isn't empty or doesn't end with just an exponent marker.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-01-18 08:51 UTC
- Runtime: 0 ms
- Memory: 8.1 MB
- Language: C++
