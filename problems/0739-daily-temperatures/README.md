# Daily Temperatures

**Difficulty:** Medium
**Tags:** stack, monotonic-stack, array

## Problem

Given an array of daily temperatures, determine for each day how many days into the future you must wait until a warmer temperature occurs. If no warmer day exists after a given day, the answer for that day is zero. The input array can contain up to 100,000 elements with temperature values between 30 and 100.

## Approach

The solution uses a monotonic decreasing stack that stores pairs of (temperature, index). As we iterate through the temperature array, we maintain the invariant that the stack contains unresolved days waiting for a warmer temperature.

For each day, we check if the current temperature is warmer than the temperatures on the stack. While this condition holds, we pop elements from the stack and calculate the waiting time as the difference between the current index and the popped index, storing this result in the output array.

After resolving all days that are warmer than the current day, we push the current day's temperature and index onto the stack. Days that remain on the stack after processing all temperatures have no future warmer day, so their answer remains the initialized value of zero.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-19 18:49 UTC
- Runtime: 123 ms
- Memory: 110.3 MB
- Language: C++
