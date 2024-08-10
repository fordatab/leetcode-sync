# Event Emitter

**Difficulty:** Medium
**Tags:** hash-table, event-handling, closure, object-oriented-design

## Problem

Design a class that manages event subscriptions and emissions, similar to Node.js EventEmitter. The class must support subscribing callback functions to named events, emitting events with optional arguments that trigger all subscribed callbacks in order, and unsubscribing callbacks. Multiple callbacks can be registered for the same event, and emit should return an array of all callback results.

## Approach

The solution uses a `Map` to store event names as keys and arrays of callback functions as values. When subscribing, the code checks if the event exists in the map; if not, it initializes an empty array for that event. The callback is pushed onto the array, and an unsubscribe object is returned that captures the callback reference via closure. The unsubscribe method finds the callback in the array using `indexOf` and removes it with `splice`. When emitting, the code retrieves the listener array for the event (returning an empty array if none exist), then iterates through all listeners, calling each with the spread arguments and collecting their return values into a results array.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-10 21:54 UTC
- Runtime: 50 ms
- Memory: 50.7 MB
- Language: JavaScript
