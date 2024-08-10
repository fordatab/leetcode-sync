# Calculator with Method Chaining

**Difficulty:** Easy
**Tags:** object-oriented-design, method-chaining, class

## Problem

The task requires implementing a Calculator class that maintains an internal result value initialized through the constructor. The class must support five mathematical operations (addition, subtraction, multiplication, division, and exponentiation) that modify the result and return the calculator instance to enable method chaining. Division by zero must throw a specific error message, and a getResult method should return the current accumulated value.

## Approach

The solution implements a straightforward object-oriented design where the Calculator class stores the running result in an instance variable `this.result`. The constructor initializes this value with the provided number.

Each arithmetic method (`add`, `subtract`, `multiply`, `divide`, `power`) performs its operation in-place on `this.result` using JavaScript's compound assignment operators (+=, -=, *=, /=) or `Math.pow()` for exponentiation. Crucially, each method returns `this`, which is the key to enabling method chaining—allowing consecutive calls like `calc.add(5).multiply(2)`.

The `divide` method includes a guard clause that checks if the divisor is zero before performing the operation, throwing an Error with the required message if so. The `getResult` method simply returns the current value of `this.result`, terminating the chain and providing the final computed value.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-10 21:55 UTC
- Runtime: 48 ms
- Memory: 48.3 MB
- Language: JavaScript
