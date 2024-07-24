# Exchange Seats

**Difficulty:** Medium
**Tags:** sql, window-function, sorting, modulo-arithmetic

## Problem

Given a table of students with sequential IDs starting from 1, swap the seat IDs of every pair of consecutive students (1↔2, 3↔4, etc.). If the total number of students is odd, the last student's ID remains unchanged. Return the result ordered by the new ID in ascending order.

## Approach

The solution uses a clever sorting trick to achieve the seat swap without explicit case logic. It orders the rows by a computed value: even IDs sort by `id-1` (moving them earlier) and odd IDs sort by `id+1` (moving them later). This effectively pairs students (1,2), (3,4), etc., with their positions swapped. For an odd-length table, the last student (odd ID) would swap with a non-existent next student, but since the ordering formula `id+1` places it at the end anyway, it naturally stays in place. After reordering, `ROW_NUMBER()` generates new sequential IDs from 1, which become the swapped seat IDs. The result is inherently ordered by the new ID since `ROW_NUMBER()` assigns them in the order of the sorted rows.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-24 08:54 UTC
- Runtime: 353 ms
- Memory: 0B
- Language: MySQL
