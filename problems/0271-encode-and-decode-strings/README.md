# Encode and Decode Strings

**Difficulty:** Medium
**Tags:** string, encoding, array, parsing

## Problem

Design an algorithm to encode a list of up to 200 strings into a single string, and decode it back to the original list. Each string can be 0-200 characters long and may contain any of the 256 ASCII characters, including special characters that could interfere with simple delimiter-based approaches. The solution must handle empty strings and arbitrary character sequences without using built-in serialization methods.

## Approach

The solution uses a length-prefix encoding scheme. During encoding, each string is prefixed with its length followed by a delimiter character '#'. For example, "Hello" becomes "5#Hello". All encoded strings are concatenated together.

During decoding, the algorithm iterates through the encoded string, parsing digits to reconstruct each length value. When a '#' delimiter is encountered, it knows the next n characters (where n is the parsed length) form one complete string. It extracts that substring and advances the position accordingly.

This approach handles all ASCII characters correctly because it doesn't rely on finding a special delimiter within the string content itself—the length prefix tells us exactly how many characters to read, regardless of what those characters are. Even if a string contains '#' or digits, they're safely encoded because the decoder uses the length count, not content scanning, to determine boundaries.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2025-11-30 05:01 UTC
- Runtime: 19 ms
- Memory: 27.3 MB
- Language: C++
