# PROBLEM - PROBLEMS ON PASCALS'S TRIANGLE

## Sub problem 1 - Given the row number and the column number return the number in the pascal's triangle

### ✅ Brute Approach

- LOGIC - Run loop to calculate every number in formula, n!, r! and (n-r)!

- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(1)

### ✅ Optimal Approach

- LOGIC -
    Start with res = 1, which will store the result.
    If r is greater than n - r, swap r with n - r to optimize calculations.
    Loop r times:
        Multiply res by (n - i), where i starts from 0 up to r - 1.
        Divide res by (i + 1).
    Return the final computed value.

- TIME COMPLEXITY - O(r)
- SPACE COMPLEXITY - O(1)

## Sub problem 2 - Given the row number, return the whole row of the pascal's triangle

### ✅ Brute Approach

- LOGIC - Loop for the n times which is the number of rows and for every iteration, calculate the 
number at that position using the ncr and add it to the result vector.

- TIME COMPLEXITY - O(Nxr)
- SPACE COMPLEXITY - O(1)

### ✅ Optimal Approach

- LOGIC - - Start with the first element 1.
-Compute each subsequent element using the previous one:
res[i] = (res[i-1] * (row - i)) / i

- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(1)

## Sub problem 3 - Given the row number create and return the full pascal's triangle

### ✅ Brute Approach

- LOGIC - Loop for the n times which is the number of rows and for every iteration, calculate the 
number at that position using the ncr and add it to the result vector.

- TIME COMPLEXITY - O(N^2)
- SPACE COMPLEXITY - O(N^2) to return the triangle

### ✅ Optimal Approach

- LOGIC - Loop for the n times which is the number of rows, and for each of that iteration, create the 
row using the optimal approach to create the row in the O(n) times.

- TIME COMPLEXITY - O(N^2) same as brute but less redundant operations
- SPACE COMPLEXITY - O(N^2) to return the triangle