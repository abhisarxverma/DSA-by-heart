from typing import List

'''
PROBLEM - Given a matrix of integers, find the median of the array, if the matrix is sorted into one single array.
Also all the rows in the matrix are soted.

EXAMPLE INPUT - 
        {1, 3, 4, 5},
        {19, 23, 32, 36},
        {48, 50, 38, 32},
        {42, 45, 46, 50}

EXAMPLE OUTPUT - 34
'''

'''
Brute Force Approach
---------------------
LOGIC - Flatten the matrix into one array, sort the array and return the median.
First loop over every row and then loop over every column in that row, add the number into a array.
Sort the array, then return the median number according to the size of the array.

TIME COMPLEXITY - O(NxM + Log(NxM)) 
SPACE COMPLEXITY - O(1)
'''

def matrix_median_brute( matrix: List[List[int]] ):
    flattened = []

    for row in matrix:
        for col in row:
            flattened.append(col)

    flattened = sorted(flattened)

    s = len(flattened)

    if s % 2 == 0: 
        return (flattened[s // 2] + flattened[s // 2 - 1]) / 2.0
    else :
        return flattened[s // 2]


'''
Optimal Approach
---------------------
LOGIC - 
Binary search on possible median values
We know the smallest and largest numbers in the matrix, so we search in that range.
Count numbers ≤ mid using upper_bound()
Since each row is sorted, we efficiently find how many elements are smaller or equal to mid.
Adjust search range
If the count is less than the required median position, we shift low up; otherwise, we decrease high.
Why? Instead of sorting the matrix, we leverage sorting within rows and binary search, reducing time complexity to O(N log max).

TIME COMPLEXITY - O(N Log(Max)) 
SPACE COMPLEXITY - O(1)
'''

def upper_bound( array: List[int], number: int ):
    low = 0
    high = len(array)

    while low < high:
        mid = low + (high - low) //2
        if array[mid] > number:
            high = mid
        else :
            low = mid + 1

    return low

def count_small_equal( matrix: List[List[int]], number: int) :
    rows = len(matrix) 
    count = 0
    for i in range(rows):
        count += upper_bound(matrix[i], number)

    return count

def matrix_median_optimal( matrix: List[List[int]] ) :
    rows = len(matrix)
    cols = len(matrix[0])
    
    low = float("inf")
    high = float("-inf")

    for i in range(rows):
        low = min(low, matrix[i][0])
        high = max(high, matrix[i][cols - 1])


    required = (rows * cols) / 2
    while low <= high:
        mid = low + (high - low) / 2
        small_equal_count = count_small_equal(matrix, mid)
        
        if small_equal_count < required:
            low = mid + 1
        else :
            high = mid - 1

    return int(low)


matrix = [
        [1, 3, 4, 5],
        [19, 23, 32, 36],
        [48, 50, 38, 32],
        [42, 45, 46, 50]
    ]
median = matrix_median_optimal(matrix)
print(f"Median : {median}")
