# Problem:  Given an integer n and an array of size n-1, which should be having intergers from 1 to n but one number is missing find that number


## ✅ Brute Force approach

- LOGIC - Loop from one to given integer and for every number loop into the given array to check if the number is present,
if not then straight return the number

- TIME COMPLEXITY - O(N^2)
- SPACE COMPLEXITY - O(1)

## ✅ Optimal Approach

- LOGIC - We have given the integer which is the number of first n natural numbers that must be there, but one is missing
so if we sum the array and calculate the sum that should the array have and subtract that then we can get the number missing.

- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(1)