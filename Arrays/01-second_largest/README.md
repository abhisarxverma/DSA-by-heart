# Problem: Find the second largest element in the array

## ✅ Brute
- Logic: Sort the array first then return the second element from start if any
- Time Complexity: O(N logN) sorting
- Space Complexity: O(N) sorted array

## ✅ Optimal
- Logic:
1. **Initialize two variables**:
   - `largest`: Tracks the largest number.
   - `second_largest`: Tracks the second largest number.

2. **Loop through the array**:
   - If the current number is **larger than `largest`**:
     - Assign `largest` to `second_largest`.
     - Update `largest` to the current number.
   - Otherwise, if the current number is **larger than `second_largest`** (but not equal to `largest`):
     - Update `second_largest` to the current number.

- Time Complexity : O(N) - one pass
- Space Complexity : O(1) 