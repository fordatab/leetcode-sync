# Check if Object Instance of Class

**Difficulty:** Medium
**Tags:** prototype-chain, object-oriented-programming, type-checking, inheritance

## Problem

Given a value and a class constructor, determine whether the value is an instance of that class or any of its superclasses. The function must handle edge cases including primitive values (which should be considered instances of their wrapper classes like Number), null/undefined values, and the fact that constructors themselves are not instances of their own class. The determination is based on whether the object has access to the class's methods via the prototype chain.

## Approach

The solution traverses the prototype chain starting from the given object. At each step, it checks if the current object's constructor matches the target class function. If a match is found, it returns true. The traversal continues by moving up the prototype chain using `Object.getPrototypeOf()` until either a match is found or the chain ends (obj becomes null). This approach naturally handles inheritance because parent class constructors will be encountered as we walk up the prototype chain. For primitives like the number 5, JavaScript's automatic boxing means `Object.getPrototypeOf(5)` returns the Number prototype, allowing the algorithm to correctly identify it as an instance of Number.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-10 21:42 UTC
- Runtime: 90 ms
- Memory: 59.4 MB
- Language: JavaScript
