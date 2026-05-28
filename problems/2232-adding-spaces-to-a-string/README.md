# Adding Spaces to a String

**Difficulty:** Medium
<<<<<<< HEAD
**Tags:** string, array, two-pointers

## Problem

Given a string and a sorted array of indices, insert a space before the character at each specified index and return the modified string. The indices are strictly increasing and indicate positions in the original string where spaces should be placed.

## Approach

The solution iterates through the `spaces` array sequentially. For each space index, it extracts the substring from the last processed position up to (but not including) the current space index using `substr`, appends it to the output string followed by a space character, then updates the tracking position to the current space index. After processing all space positions, it appends the remaining portion of the original string from the last space position to the end. This builds the result incrementally by concatenating substrings with spaces inserted at the correct positions.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2026-04-21 23:09 UTC
- Runtime: 26 ms
- Memory: 86.8 MB
=======
**Tags:** string, array, two-pointers, string-builder

## Problem

Given a string and an array of indices, insert spaces before the characters at those indices and return the modified string. The indices are sorted in strictly increasing order, and each space should be placed before the character at the specified position. The string can be up to 300,000 characters long, and there can be up to 300,000 space positions.

## Approach

The solution uses a `stringstream` to efficiently build the result string. It maintains a pointer `i` to track the current position in the original string. For each space position in the `spaces` array, it extracts the substring from the current position `i` to the space position using `substr()`, appends it to the stream followed by a space character, then updates `i` to the space position. After processing all space positions, it appends the remaining portion of the original string (from the last space position to the end). Finally, it converts the stringstream to a string and returns it.

The key insight is that since the space positions are sorted, we can process them sequentially in a single pass, building segments of the original string separated by spaces without needing to shift characters or make multiple passes.

## Complexity

- **Time:** O(n + m)
- **Space:** O(n + m)

## Stats

- Submitted: 2026-04-21 23:15 UTC
- Runtime: 21 ms
- Memory: 89.6 MB
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d
- Language: C++
