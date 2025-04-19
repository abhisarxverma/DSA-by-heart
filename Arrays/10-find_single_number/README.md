# Problem: Given an array with numbers which are apprearing twice in order but one number is alone find that number
### Example input : { 1, 1, 2, 2, 3, 4, 4 }
### Example output : 3

## ✅ Brute Force approach

- LOGIC - Loop over the array taking two steps and check if the next number is equal to the current number if not return that number

- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(1)

## ✅ Optimal approach

- LOGIC - XOR concept, if you XOR same numbers the result will be 0 and if you XOR a number with zero, you will get
the number itself. So if you do XOR of the array, the numbers will cancel out and the single number will be left out.

- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(1)