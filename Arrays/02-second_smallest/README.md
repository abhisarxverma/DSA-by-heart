# Problem: Find the second smallest element in the array

## ✅ Brute
- Logic: Sort the array first then return the second last start if any
- Time Complexity: O(N logN) sorting
- Space Complexity: O(N) sorted array

## ✅ Optimal
- Logic: Take two variables smallest and second smallest, loop the array, if the number is smaller than smallest then store the smallest in the second smallest and make the smallest that number and if the number is not smaller than the smallest then check if it is smaller than second smallest because it may be the case where any number is not smaller than the smallest but is smaller than the second smallest and in that case the second smallest should be updated to that number. OVER.

- Time Complexity : O(N) - one pass
- Space Complexity : O(1) 