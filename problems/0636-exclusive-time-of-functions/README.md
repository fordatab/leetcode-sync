# Exclusive Time of Functions

**Difficulty:** Medium
**Tags:** stack, string-parsing, simulation, call-stack

## Problem

Given n functions executing on a single-threaded CPU with a call stack, calculate the exclusive execution time for each function. Each log entry specifies a function ID, whether it started or ended, and a timestamp. Start events occur at the beginning of a timestamp and end events at the end of a timestamp. Functions can call themselves recursively or other functions, and the task is to compute the total time each function spent executing (excluding time when other functions were running on top of it in the call stack).

## Approach

The solution uses a stack to track the currently executing function along with the last timestamp it was actively running. For each log entry:

1. Parse the log into function ID, event type (start/end), and timestamp.
2. If the stack is not empty, calculate the elapsed time since the current top function last started executing and add it to that function's total.
3. For "end" events: increment the function's time by 1 (since end happens at the end of the timestamp), pop it from the stack, and update the new top's timestamp to resume at the next unit.
4. For "start" events: update the current top's resume timestamp to be after this new function starts, then push the new function onto the stack.

The stack maintains the call hierarchy, and the timestamp tracking ensures each function only accumulates time when it's actually at the top of the stack (actively executing).

## Complexity

- **Time:** O(m)
- **Space:** O(n)

## Stats

- Submitted: 2026-03-05 05:15 UTC
- Runtime: 94 ms
- Memory: 18.6 MB
- Language: C++
