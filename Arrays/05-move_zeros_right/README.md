# Problem: Given an array take all the zeros to the right

## ✅ Brute
- LOGIC - Take a new list, loop the given array and store the nonzero numbers in the vector and count the number of zeros, then fill the remaining places to the zeros.

- TIME COMPLEXITY - O(2N) = O(N) - due to sorting
- SPACE COMPLEXITY - O(N) - new list

## ✅ Brute-2 Approach
- LOGIC -  Using the bubble sort, if any number is zero swap it with the right number, do this till the zero comes to the extreme right as in bubble sort the biggest number comes to the extreme right.

- TIME COMPLEXITY - O(N^2) - bubble sort complexity
- SPACE COMPLEXITY - O(1)

## ✅ Better Approach
- LOGIC - Using the concept of quicksort, the right pointer 'j' will find the nonzero number and the left pointer 'i' will find the zero number and they will swap with each other till they becomes equal means no zeros left. but the sequence will be distorted 

- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(1)
**but non-zero numbers will not be in exact sequence**

## ✅ Optimal Approach
- LOGIC - Two pointer approach, take two pointer and move the first pointer to the first zero, and then loop from the front of it to the end of array
if you find a non zero then as the j have the zero, swap them so that the zero will be replaced by the number, this will take all the zeros to right.

- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(1)