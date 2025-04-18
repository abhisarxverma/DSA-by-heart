# Problem: Find the second smallest element in the array

## ✅ Brute
- Logic: Sort the array first then return the second last start if any
- Time Complexity: O(N logN) sorting
- Space Complexity: O(N) sorted array

## ✅ Optimal
- Logic:
1. **Initialize two variables**:
   - `smallest`: Tracks the smallest number.
   - `second_smallest`: Tracks the second smallest number.

2. **Loop through the array**:
   - If the current number is **smaller than `smallest`**:
     - Assign `smallest` to `second_smallest`.
     - Update `smallest` to the current number.
   - Otherwise, if the current number is **smaller than `second_smallest`** (but not equal to `smallest`):
     - Update `second_smallest` to the current number.

- Time Complexity : O(N) - one pass
- Space Complexity : O(1) 