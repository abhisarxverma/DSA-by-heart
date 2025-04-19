# Problem: Given an array of zeros and ones find the maximum number of consecutive ones in the array

## ✅ Brute Force approach

- LOGIC - Take a final_count and a temp_count, loop over the array, while you are encountering ones increment the temp_count and if a number comes which
is not one then, check if the temp count is greater than the final count, if yes update the final count else pass on.

- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(1)
