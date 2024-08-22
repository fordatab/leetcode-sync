# Excel Sheet Column Number

**Difficulty:** Easy
**Tags:** string, math, base-conversion

## Problem

Convert an Excel-style column title (using letters A-Z) into its corresponding numeric position. The system works like base-26 numbering where A=1, B=2, ..., Z=26, AA=27, AB=28, and so on. The input string has length between 1 and 7 characters and contains only uppercase English letters.

## Approach

The solution treats the column title as a base-26 number system and converts it to decimal. It iterates through each character from left to right, multiplying the running total by 26 (shifting one position in base-26) and adding the numeric value of the current character. Each character's value is computed by subtracting 64 from its ASCII code (since 'A' is ASCII 65, subtracting 64 gives 1). For example, "AB" becomes: 0 → 0×26+1=1 (for 'A') → 1×26+2=28 (for 'B'). This is essentially Horner's method for polynomial evaluation applied to base conversion.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-22 08:56 UTC
- Runtime: 2 ms
- Memory: 8.7 MB
- Language: C++
