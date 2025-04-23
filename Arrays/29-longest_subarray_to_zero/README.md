# PROBLEM - Given an array of integers, return the longest length of the contiguous subarray that sum to 0.

### EXAMPLE INPUT - [ -3, 7, 2, -2, -7 ]
### EXAMPLE OUTPUT - 4


## ✅ Brute Approach

- LOGIC - Take a final length variable and Loop over the array , then loop over the right part of the current number in first array, if you find the 
sum 0, update the final length if greater.

- TIME COMPLEXITY - O(N^2)
- SPACE COMPLEXITY - O(1)

## ✅ Optimal Approach

- LOGIC - 
    ## **Approach**
    - Use a **hashmap** to store prefix sums encountered during array traversal.
    - A subarray sum can be **zero** in two cases:
    1. **Direct zero sum:** If the prefix sum itself is `0`, the subarray length is `index + 1`.
    2. **Previously seen prefix sum:** Removing the earlier portion results in a zero-sum subarray. The length in this case is `current index - stored index`.

    ## **Updating the Result**
    - Track the **maximum subarray length** found.
    - Store the index of each unique prefix sum in the hashmap for future reference.
    - If a longer subarray is found, update the result.

- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(N) *hashmap*