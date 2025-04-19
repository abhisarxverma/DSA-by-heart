# Problem: Given two sorted arrays return a union array with the unqiue elements

## ✅ Brute Force approach
**Brute force solution may differ little in c++ and python**

- LOGIC - Take a set, and a result vector, loop through all the number in the both arrays, if the number not in set then only add
it to the set and the vector, else do nothing, then at last sort and return vector

- TIME COMPLEXITY - O( (N+M) x Log(N+M) ) for sorting
- SPACE COMPLEXITY - O( 2(N+M) ) set and list

## ✅ Optimal Approach
- LOGIC - Using the merge sort concept of merging two sorted arrays

- TIME COMPLEXITY - O(N+M Log N+M) 
- SPACE COMPLEXITY - O(N+M)