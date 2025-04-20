# PROBLEM - Given an array of prices, give the maximum profit that we can get if we buy and then sell. 

### Example input : [5, 1, 3, 2, 7]
### Example output : [1, 7]

## ✅ Brute Force approach

- LOGIC - Loop over the array, and for every number, loop over the array next to it, and store the maximum difference
and return the greatest.

- TIME COMPLEXITY - O(N^2)
- SPACE COMPLEXITY - O(1)

## ✅ Better approach

- LOGIC - If you think carefully, we just have to find the difference between the minimum and the maximum 
or maybe their indexes. So, while iterating, keep track of the minimum number before it and update the final
profit based on the difference.

- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(1)