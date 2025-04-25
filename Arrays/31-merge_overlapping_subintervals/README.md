# PROBLEM - Given an array of intervals of integers, merge the intervals.

### EXAMPLE INPUT - {{1, 3}, {2, 6}, {8, 10}, {9, 12}}
### EXAMPLE OUTPUT - { {1, 6}, {8, 12} }


## ✅ Brute Approach

- LOGIC - 
    1. Use a **set** to store unique merged intervals.
    2. Loop over the intervals:
    - Initialize `low` and `high` to the first interval’s bounds.
    - Check if the current interval extends `low` or `high`, update accordingly.
    3. After processing, add the merged interval to the **set**.
    4. Repeat for the remaining intervals to ensure uniqueness.

- TIME COMPLEXITY - O(N^2) two-nested-loops
- SPACE COMPLEXITY - O(N) set

## ✅ Optimal Approach

- LOGIC - 
    1. **Sort** the intervals by starting point.
    2. Initialize `low` and `high` with the first interval's bounds.
    3. Loop through intervals:
    - **Expand `high`** if the current interval starts within `[low, high]` and extends beyond `high`.
    - **Reduce `low`** if the current interval’s end falls within `[low, high]` and is lower than `low`.
    4. Store the finalized merged interval.
    5. Repeat for remaining intervals.

- TIME COMPLEXITY - O(N logN)
- SPACE COMPLEXITY - O(1)
