# PROBLEM - Count the total number of the pairs that can be formed in which the first element is greater than the second one.

### EXAMPLE INPUT - {8, 6, 1, 7, 5, 2, 3, 8}
### EXAMPLE OUTPUT - 15


## ✅ Brute Approach

- LOGIC - Loop over the array and then loop over the right of the array and increase the count if 
you find a pair in which the second element is smaller than the frist one.

- TIME COMPLEXITY - O(N^2) two-nested-loops
- SPACE COMPLEXITY - O(1)

## ✅ Optimal Approach

- LOGIC - MERGE SORT APPROACH -
  1. Counting split inversions when merging two sorted halves.
  2. Keeping track of how many elements in the right half are **smaller** than the current element in the left half.

- TIME COMPLEXITY - O(N LogN) Merge sort time complexity
- SPACE COMPLEXITY - O(N) temporary space for merging