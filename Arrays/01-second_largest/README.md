# Problem: Find the second largest element in the array

## ✅ Brute
- Logic: Sort the array first then return the second element from start if any
- Time Complexity: O(N logN) sorting
- Space Complexity: O(N) sorted array

## ✅ Optimal
- Logic: Take two variables largest and second largest, loop the array, if the number is greater than largest then store the largest in second largest and make the largest that number and if the number is not greater than the largest then check if it is greater than second largest cause it may be the case where any number is not greater than the largest but is greater than the second largest and in that case the second largest should be updated to that number. OVER.

- Time Complexity : O(N) - one pass
- Space Complexity : O(1) 