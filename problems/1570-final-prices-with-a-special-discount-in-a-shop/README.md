# Final Prices With a Special Discount in a Shop

**Difficulty:** Easy
**Tags:** monotonic-stack, stack, array

## Problem

Given an array of item prices, calculate the final price for each item after applying a special discount. For each item at index i, the discount equals the price at the nearest subsequent index j where the price is less than or equal to the current item's price. If no such subsequent item exists, no discount applies. The array can contain up to 500 items with prices ranging from 1 to 1000.

## Approach

This solution uses a monotonic stack to efficiently find the next smaller or equal element for each price. The algorithm traverses the prices array once from left to right. For each price, it maintains a stack of (price, index) pairs representing items that haven't yet found their discount.

When processing each element, the code pops all stack entries whose prices are greater than or equal to the current price — these are items that can use the current price as their discount. The final price for each popped item is calculated as the original price minus the current price (the discount), and stored at the corresponding index in the output array.

After processing the current price, it's pushed onto the stack to potentially serve as a discount for future items. Once all prices are processed, any remaining items on the stack have no valid discount, so their final prices equal their original prices. The stack ensures each element is pushed and popped at most once, making the solution linear in time.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-19 06:30 UTC
- Runtime: 6 ms
- Memory: 12.6 MB
- Language: C++
