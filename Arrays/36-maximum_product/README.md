# PROBLEM - Find the maximum product that you can get from all the subarrays of the given array


### EXAMPLE INPUT - {2, -1, 5, 7, -2, -9, 10, -6}
### EXAMPLE OUTPUT - 75600


## ✅ Brute Approach

- LOGIC - Loop over the array and then loop over the right of the outer loop's number, and multiply while
updating the final product

- TIME COMPLEXITY - O(N^2) two-nested-loops
- SPACE COMPLEXITY - O(1)

## ✅ Optimal Approach

- LOGIC - 
    - Since the product can be affected by negative numbers and zeros, we need to check both left-to-right (prefix) and right-to-left (suffix).
    - Multiplying continuously from start to end and end to start ensures we correctly handle negative flips.
    - Traverse the array from left to right (prefix).
    Simultaneously traverse from right to left (suffix).
    - Reset product when encountering zero (pre = 1, suf = 1), ensuring we start fresh after a zero.
    - Keep track of the maximum product found.
    - Since negatives can flip signs, checking from both ends ensures we do not miss a case where multiplying a negative later leads to a higher product.

TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(1)