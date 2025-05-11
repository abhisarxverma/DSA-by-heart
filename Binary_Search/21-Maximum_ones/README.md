# PROBLEM - Given a 2d matrix of 0s and 1s, in which the rows are sorted, find the row number with the maximum 1s, in case of the multiples return the minimum index.

### INPUT - 
        {0, 0, 1, 1, 1},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 1, 1}

### OUTPUT - 1 

## ✅ Brute Force Approach

- **LOGIC** - *Double nested looping*
    - Take a highest count variable
    - Loop over every row, then loop over every column
    - We will take little advantage of the sorted feature of the rows in matrix
    - As soon as we find the first one in the column, we will add the total count of ones in that row
    - Total count will be `Total columns - First one index` to the current count
    - update the highest if the current_count is greater than the highest
    - return the highest

- **TIME COMPLEXITY** - ***O(N x M)***
- **SPACE COMPLEXITY** - ***O(1)***

## ✅ Optimal Approach

- **LOGIC** - *Binary search*
    - We will loop over every row
    - And as the rows are sorted We will find the first occurence of the "1" using Binary search
    - If first 1 found then it's count will be `total columns - first occurence index`
    - If the count is greater than the highest count then update the highest count and the highest index which we have to return.

- **TIME COMPLEXITY** - ***O(N x Log(M))***
- **SPACE COMPLEXITY** - ***O(1)***