# Problem: Given an array, find the maximum sum that can be taken out from the contiguous part of the array
### Example input : [5, 1, -7, 3, 0]
### Example output : 6

## ✅ Brute Force approach

- LOGIC - Loop over the array, and for every number, loop over the array next to it, and store the maximum sum
and return the greatest.

- TIME COMPLEXITY - O(N^2)
- SPACE COMPLEXITY - O(1)

## ✅ Optimal approach

- LOGIC - KADANE'S ALGORITHM - While looping in the array, store the sum, if the sum drops to negative
then turn it back to zero, and if the sum is positive then keep it increasing

- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(1)