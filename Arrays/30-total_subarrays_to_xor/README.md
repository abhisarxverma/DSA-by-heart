# PROBLEM - Given an array of integers, return the total number of the contiguous subarrays that give the target xor k.

### EXAMPLE INPUT - 4, 2, 2, 6, 4 , k = 6
### EXAMPLE OUTPUT - 4


## ✅ Brute Approach

- LOGIC - Take the variable count, and loop over the array, then loop over the right side of the first loop element, 
and check the xor if equal to the target then increase the count else pass.

- TIME COMPLEXITY - O(N^2)
- SPACE COMPLEXITY - O(1)

## ✅ Optimal Approach

- LOGIC - 
    1. Use a hashmap to store prefix xor while looping over the array. 
    2. Check if the there exist the number [prefix_xor ^ k] in hashmap, if yes then add in the count the value of that number in map
    3. Update the final length if a longer subarray is found, while storing indices of prefix xor for future reference. 🚀

- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(N) *hashmap*