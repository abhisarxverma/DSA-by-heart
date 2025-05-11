## PROBLEM - Given a matrix, and a number to find, return the row and column number of that number. Every column and every row in matrix are internally sorted, but the matrix as a whole is not sorted.

### EXAMPLE INPUT - 
        {1, 5, 10, 15},
        {19, 23, 32, 36},
        {32, 38, 39, 48},
        {42, 45, 46, 50}

        Number = 39

### EXAMPLE OUTPUT - (2, 2)

## ✅ Brute Force Approach

- **LOGIC** - *Double nested loops*
    - Loop over every row and then loop over every column
    - return the row and column number if found, else return (-1, -1)

- **TIME COMPLEXITY** - ***O(N x M)***
- **SPACE COMPLEXITY** - ***O(1)***

## ✅ Better Approach

- **LOGIC** - *Check the range and then do binary search*
    - Loop over the rows, and because the row is sorted we can check that the number we are finding is in that range or not
    - If the number is in that range then do the binary search and find the number, also note there can be multiple rows with the range that can have the number
    - That's why we need to check every row with the range we need
    - return the row and column number if number found, else return `(-1, -1)`

- **TIME COMPLEXITY** - ***O(N x LogM)***
- **SPACE COMPLEXITY** - ***O(1)***

## ✅ Optimal Approach

- **LOGIC** - *Taking advantage of the sorted row and columns internally*
    - We will have two variables `i` and `j`
    - `i` will be at the top row which is 0 index of matrix
    - `j` will be at the last column of top row which is `total columns-1` index
    - And do a while loop till the `i` pointer becomes equal to the `total rows-1` and `j` pointer becomes `-1`
    - Means we will start form the top right corner of the matrix
    - In the loop we will check if the number at the point is the number we are finding if yes return that row and column index
    - And if the number at that point is greater than the number we are finding, then this means that all the numbers in that column further are greater
    - Hence we will discard that column completely and search in one column before
    - But also if the number at that point is smaller than the number we are finding then this means that all the numbers in that row before are smaller 
    - Hence we will discard that row completely and search in the next row 
    - We will repeat this process and eventually if number is present we will get that.

- **TIME COMPLEXITY** - ***O(N + M)***
- **SPACE COMPLEXITY** - ***O(1)***