# Decode the Message

**Difficulty:** Easy
**Tags:** hash-table, string, substitution-cipher, array

## Problem

Given a cipher key string and an encoded message, decode the message using a substitution cipher. The substitution table is built by mapping each letter's first appearance in the key (ignoring spaces and duplicates) to consecutive letters of the alphabet starting from 'a'. Spaces in the message remain unchanged. The key is guaranteed to contain all 26 lowercase letters at least once, and both strings may be up to 2000 characters long.

## Approach

The solution builds a substitution mapping by iterating through the key string once. It uses a vector of size 26 to store the mapping from each letter in the key to its corresponding alphabet position. For each character in the key that is a letter (not a space) and hasn't been seen before (tracked by checking if its mapping is still -1), it assigns the next sequential alphabet position (0 for 'a', 1 for 'b', etc.).

Once the mapping is constructed, the solution decodes the message in-place by iterating through each character. For lowercase letters, it looks up the substitution value in the mapping vector and converts it back to the corresponding alphabet character by adding 'a'. Space characters are left untouched since they don't satisfy the lowercase letter condition.

The key insight is that tracking first appearances with a sentinel value (-1) allows building the mapping in a single pass, and modifying the message string in-place avoids allocating additional space for the result.

## Complexity

- **Time:** O(n + m)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-13 10:30 UTC
- Runtime: 5 ms
- Memory: 8.3 MB
- Language: C++
