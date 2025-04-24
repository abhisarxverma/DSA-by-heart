# PROBLEM - Given an two sorted arrays, sort them without using any extra space inplace and return them.


### EXAMPLE INPUT - {2, 9, 10} {5, 8, 15, 19}
### EXAMPLE OUTPUT - {2, 5, 8} {9, 10, 15, 19}


## ✅ Brute Approach

- LOGIC - Use the Merge sort merging algorithm to merge the two arrays, and at last put the sorted array's elements back into the original two arrays according to their original sizes.

- TIME COMPLEXITY - O(N+M) merging
- SPACE COMPLEXITY - O(N+M) merged sorted array

## ✅ Better Approach

- LOGIC - 
    1. **Resize `array1`** to accommodate elements of `array2`.
    2. Use three pointers:
    - `i` → Last element of original `array1`
    - `j` → Last element of `array2`
    - `k` → Last position in expanded `array1`
    3. **Merge in reverse order**:
    - Place the larger element from `array1[i]` or `array2[j]` at `array1[k]`.
    - Move pointers accordingly.
    4. **Handle remaining elements** from `array2` if any are left.
    5. **Split `array1` back** so both arrays retain sorted elements separately.

- TIME COMPLEXITY - O(N+M) 
- SPACE COMPLEXITY - O(M)

## ✅ Optimal Approach

- LOGIC - 
    1. **Initialize gap = (n + m + 1) // 2**.
    2. Compare elements at index `i` and `j`:
    - **Both in `array1`** → Swap if `array1[i] > array1[j]`.
    - **One in `array1`, one in `array2`** → Swap if `array1[i] > array2[j-n]`.
    - **Both in `array2`** → Swap if `array2[i-n] > array2[j-n]`.
    3. Reduce gap → `gap = (gap + 1) // 2` until **gap = 0**.

- TIME COMPLEXITY - O((n+m) log(n+m))
- SPACE COMPLEXITY - O(1)