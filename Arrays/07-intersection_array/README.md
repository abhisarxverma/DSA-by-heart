# Problem: Given two sorted arrays return a intersection array with uniques

## ✅ Brute Force approach

- LOGIC - Loop over the any one vector, the nestedly loop over other vector, and if you find any number same as the outer number 
then add it to the result vector, and it will automatically be in sorted order, so no need to sort.
straight return the result vector.

- TIME COMPLEXITY - O((N+M)^2)
- SPACE COMPLEXITY - O(N+M) result array to return

## ✅ Optimal Approach

- LOGIC - Using the merge sort concept of merging two sorted arrays
- TIME COMPLEXITY - O(N+M) 
- SPACE COMPLEXITY - O(N+M)