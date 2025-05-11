# PROBLEM - Given a full sorted matrix, means the whole matrix as one array, is sorted and you have to find the given number in the matrix.

### INPUT -
        {1, 5, 10, 15},
        {19, 23, 27, 30},
        {32, 35, 39, 40},
        {42, 45, 46, 50}

        Number = 39

### OUTPUT - True

## ✅ Brute Force Approach

- **LOGIC** - *Double nested looping*
    - Loop over every number in row,
    - if you find the nubmer, return True
    - else return False

- **TIME COMPLEXITY** - ***O(N x M)***
- **SPACE COMPLEXITY** - ***O(1)***

## ✅ Better Approach

- **LOGIC** - *Check if the number really is present in row and if yes then do binary search.*
    - Loop over the row, compare the number we need to find to the low and high
    - If the number is in that range, then do the binary search in that row and find the number
    - if found return True, then return False

- **TIME COMPLEXITY** - ***O(N + LogM)***
- **SPACE COMPLEXITY** - ***O(1)***

## ✅ Optimal Approach

- **LOGIC** - *Binary search*
    - Cause the whole matrix is sorted we can do normal binary seach
    - We will take mid but also we will do modulos to the rows and cols
    - So that the mid gets to the right row and the column
    - And normally discard left and right half according to the conditions.

- **TIME COMPLEXITY** - ***O(Log (NxM))***
- **SPACE COMPLEXITY** - ***O(1)***