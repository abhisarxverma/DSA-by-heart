## PROBLEM - Given a matrix, in which every 2 elements are different, and the rows and columns are not sorted, Also, you can assume that the border of the matrix is -1. This means that you can assume that the number next or before to the numbers at end are -1. Find the greatest Peak element and return that.

### EXAMPLE INPUT - 
        {1, 3, 4, 5},
        {19, 23, 32, 36},
        {48, 50, 38, 32},
        {42, 45, 46, 50}

### EXAMPLE OUTPUT - 50

## ✅ Brute Force Approach

- **LOGIC** - Double nested Looping over rows and columns
    - Loop over rows and then loop over the columns
    - if you find a number which is greater than both of its side number in that row
    - then return the number

- **TIME COMPLEXITY** - ***O(N x M)***
- **SPACE COMPLEXITY** - ***O(1)***

## ✅ Optimal Approach

- **LOGIC** - *Binary search peak element method*
    - The logic here is based in the normal peak element algorithm of binary search
    - In the normal prodecure we tried to go to the right if the mid is in the ascending portion
    - And we tried to go to the left if the mid is in the descending portion.
    - Why? cause if there is no peak element in array, if the array is ascending the last number will always be the peak element
    - and if the array is descending the first number will always be the peak element and we try to go that direction.
    - But, here one condition added to this normal peak element search is that the peak element must also be greater than the upper and lower numbers
    - So we will have a helper function that will give us the index of the largest number in any column given
    - While doing the binary search on the columns we will pass the mid to the function and get the index of the largest number
    - Taking the largest number in column already solves the half the problem. Cause alreay we are first going to the number in column that is greater than both of it's upper and lower number
    - Now we will do the same peak element search thing, we will go right or left according to the ascending or descending.
    - This will give us the peak element, 

- **TIME COMPLEXITY** - ***O(N x LogM)***
- **SPACE COMPLEXITY** - ***O(1)***