# PROBLEM - Given an array, find the leaders in the array, the numbers which have no elements on the right greater than them.

### Input : {5, 2, 9, 7, 3}
### Output : {3, 7, 9}

## ✅ Brute Approach

- LOGIC - Loop over the array, and then loop over the array on the right of them, if you find any element greater then stop and
if not, add it to the result array

- TIME COMPLEXITY - O(N^2)
- SPACE COMPLEXITY - O(1)

## ✅ Optimal Approach

- LOGIC - If you think carefully, the leaders are the numbers which are greater than the max on the right. So iterate from the right, and store the max number, if the current number is greater than the max then add it to the result array. else pass.

- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(1)