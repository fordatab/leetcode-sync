# Number Complement

**Difficulty:** Easy
**Tags:** bit-manipulation, bitwise-xor, masking

## Problem

Given a positive integer, return the complement obtained by flipping all bits in its binary representation (excluding leading zeros). For instance, 5 in binary is 101, and flipping each bit gives 010, which is 2. The input is guaranteed to be between 1 and 2^31 - 1.

## Approach

The solution uses a bit manipulation technique with a mask. It starts with a mask of all 1s (unsigned ~0). The mask is then left-shifted repeatedly until it no longer overlaps with any of the set bits in the input number — this creates a mask where all bits corresponding to the significant bits of `num` are 0, and all higher bits are 1.

Once the mask is positioned correctly, the code computes `~num` (which flips all bits, including leading zeros) and then XORs it with the mask. This XOR operation effectively cancels out the unwanted leading 1s that appeared when we negated `num`, leaving only the complement of the original significant bits.

For example, with num=5 (binary 101): the mask becomes 11111000 after shifting, ~num becomes 11111010, and XORing them yields 00000010 (which is 2).

## Complexity

- **Time:** O(log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-22 23:18 UTC
- Runtime: 0 ms
- Memory: 7.5 MB
- Language: C++
