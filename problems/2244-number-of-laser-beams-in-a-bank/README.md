# Number of Laser Beams in a Bank

**Difficulty:** Medium
**Tags:** array, string, counting, math

## Problem

Given a 2D grid representing a bank floor plan where '1' denotes a security device and '0' an empty cell, count the total number of laser beams. A laser beam exists between every pair of devices on two different rows only if all rows between them contain no devices. The grid dimensions can be up to 500×500.

## Approach

The solution works by first counting the number of security devices ('1's) in each row and storing these counts in a vector, but only for rows that have at least one device (skipping empty rows). Once we have this list of device counts per non-empty row, we calculate the total beams by multiplying consecutive pairs of counts. For each adjacent pair of non-empty rows, the number of beams between them equals the product of their device counts (since each device in one row connects to each device in the next non-empty row). The final answer is the sum of all these products. If there are no rows with devices, the function returns 0.

## Complexity

- **Time:** O(m * n)
- **Space:** O(m)

## Stats

- Submitted: 2024-07-26 02:27 UTC
- Runtime: 83 ms
- Memory: 27.2 MB
- Language: C++
