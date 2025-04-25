# PROBLEM - COUNT THE NUMBER OF THE REVERSE PAIRS WHICH ARE THE PAIRS IN WHICH THE LEFT ELEMENT IS MORE THAN TWICE OF THE RIGHT ELEMENT SIMILAR TO THE COUNT INVERSIONS

### EXAMPLE INPUT - {8, 6, 1, 7, 5, 2, 3, 8}, n = 8
### EXAMPLE OUTPUT - 8


## ✅ Brute Approach

- LOGIC - Loop over the array and then loop over the array on the right and increase the count
if you find any pair in which the first element is greater than the double the second element.

- TIME COMPLEXITY - O(N^2) two-nested-loops
- SPACE COMPLEXITY - O(1)

## ✅ Optimal Approach

- LOGIC - MERGE SORT APPROACH - 
  1. Before merging, counting elements in the right half where `array[i] > 2 * array[j]` using a two-pointer technique.
  2. Merging the two halves while maintaining order.

- TIME COMPLEXITY - O(N LogN) Merge sort approach
- SPACE COMPLEXITY - O(N) temporary array for merging