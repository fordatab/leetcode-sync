# Average Time of Process per Machine

**Difficulty:** Easy
**Tags:** sql, self-join, aggregation, database

## Problem

Given a table tracking machine process events with start and end timestamps, calculate the average processing time per machine. Each machine runs multiple processes, and each process has exactly one start and one end event. The result should show each machine's ID and its average processing time rounded to three decimal places.

## Approach

The solution uses a self-join on the Activity table to pair start and end events for each process. It joins rows where the machine_id and process_id match, but enforces that one timestamp is earlier than the other (a1.timestamp < a2.timestamp), effectively pairing each 'start' event with its corresponding 'end' event. For each paired row, it calculates the duration (a2.timestamp - a1.timestamp), then groups by machine_id and computes the average of all durations for that machine. The ROUND function ensures the result is formatted to exactly 3 decimal places as required.

## Complexity

- **Time:** O(n²)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-25 05:03 UTC
- Runtime: 244 ms
- Memory: 0B
- Language: MySQL
