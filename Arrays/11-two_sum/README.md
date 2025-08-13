# Problem: Given an array and a sum tell if this sum is possible by adding any two elements in an array
### Example input : [1, 5, 7, 0, 10], sum = 15
### Example output : { 1, 4 } 
***1st index - 5, 4th index - 10, sum = 15***

## ✅ Brute Force approach

- LOGIC - Loop over the  array and again loop over the array leaving the outer loop index, and check if the
the pair give the required sum ,then return the vector having the index of that pair.

- TIME COMPLEXITY - O(N^2) - Double looping
- SPACE COMPLEXITY - O(1)

## ✅ Optimal approach

- LOGIC - Using a hashmap, while looping storing the numbers visited and for the current loop number
we will check if the number exist in the hashmap , if yes, then return the current number index and 
the value of that complement number in hashmap which is it's index, if we not find any complement in 
hashmap then simply add the current loop number to hashmap with index, and pass on.

- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(N) - hashmap

## ✅ Optimal approach 2 ***( This can give true or false rather than indexes )***

- LOGIC - Sort the array, then take two pointers one at start and one at end, compare the sum of the numbers at the two pointers
to the target sum, if the current sum is low, then move the first pointer forward, otherwise move the last pointer backward
This is optimal but cannot return the indexes because sorting alter the indexes.

- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(1)