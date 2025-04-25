# PROBLEM - Count the total number of the pairs that can be formed in which the first element is greater than the second one.

### EXAMPLE INPUT - {8, 6, 1, 7, 5, 2, 3, 8}
### EXAMPLE OUTPUT - 15


## ✅ Brute Approach

- LOGIC - Loop over the array and then loop over the right of the array and increase the count if 
you find a pair in which the second element is smaller than the frist one.

- TIME COMPLEXITY - O(N^2) two-nested-loops
- SPACE COMPLEXITY - O(1)

## ✅ Optimal Approach

- LOGIC - MERGE SORT APPROACH - Using the MERGESORT concept of merging the sorted arrays. while merging we will get the count by compairing the elements with the trick

- TIME COMPLEXITY - O(N LogN) Merge sort time complexity
- SPACE COMPLEXITY - O(N) for merging