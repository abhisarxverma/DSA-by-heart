## PROBLEM - Given a matrix of integers, find the median of the sorted matrix. Also all the rows in the matrix are sorted.

### EXAMPLE INPUT - 
        {1, 3, 4, 5},
        {19, 23, 32, 36},
        {48, 50, 38, 32},
        {42, 45, 46, 50}

### EXAMPLE OUTPUT - 34

## ✅ Brute Force Approach

- **LOGIC** - Flatten the matrix into one array, sort the array and return the median.
    - First loop over every row and then loop over every column in that row, add the number into a array.
    - Sort the array, then return the median number according to the size of the array.

- **TIME COMPLEXITY** - ***O(NxM + Log(NxM))***
- **SPACE COMPLEXITY** - ***O(1)***

## ✅ Optimal Approach

- **LOGIC** - *Binary search on possible median values*
    - We know the smallest and largest numbers in the matrix, so we search in that range.
    - Count `numbers ≤ mid`using `upper_bound()`
    - Since each row is sorted, we efficiently find how many elements are smaller or equal to mid.
    - Adjust search range
    - If the count is less than the required median position, we shift low up; otherwise, we decrease high.
    - Why? Instead of sorting the matrix, we leverage sorting within rows and binary search, reducing time complexity to `O(N log max)`.

- **TIME COMPLEXITY** - ***O(N Log(Max))*** 
- **SPACE COMPLEXITY** - ***O(1)***