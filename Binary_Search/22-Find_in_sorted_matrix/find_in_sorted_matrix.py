from typing import List

'''
PROBLEM - Given a full sorted matrix, means the whole matrix as one array, is sorted and you have to find the given number in the matrix.

INPUT - {1, 5, 10, 15},
        {19, 23, 27, 30},
        {32, 35, 39, 40},
        {42, 45, 46, 50}

        Number = 39

OUTPUT - True
'''

'''
Brute Force Approach
---------------------
LOGIC - Double nested looping
Loop over every number in row,
if you find the nubmer, return True
else return False

TIME COMPLEXITY - O(N x M) 
SPACE COMPLEXITY - O(1)
'''

def find_in_sorted_matrix_brute( matrix: List[List[int]], number: int ):
    rows = len(matrix)
    cols = len(matrix[0])

    for row in matrix:
        for col in row:
            if col == number: return True

    return False

'''
Better Approach
---------------------
LOGIC - Check if the number really is present in that range.
Loop over the row, compare the number we need to find to the low and high
If the number is in that range, then do the binary search in that row and find the number
if found return True, then return False

TIME COMPLEXITY - O(N + LogM) 
SPACE COMPLEXITY - O(1)
'''

def find_in_sorted_matrix_better( array: List[List[int]], number: int ):
    rows = len(array)
    cols = len(array[0])

    for row in matrix:
        if number < row[0] or number > row[-1]: continue
        low = 0
        high = cols-1
        while low <= high:
            mid = low + (high-low)//2
            if row[mid] == number: return True
            if row[mid] > number: high = mid-1
            else:low = mid+1

    return False

'''
Optimal Approach
---------------------
LOGIC - Binary search
Cause the whole matrix is sorted we can do normal binary seach
We will take mid but also we will do modulos to the rows and cols
So that the mid gets to the right row and the column

TIME COMPLEXITY - O(Log (NxM)) 
SPACE COMPLEXITY - O(1)
'''

def find_in_sorted_matrix_optimal( matrix: List[List[int]], number: int ):
    rows = len(matrix)
    cols = len(matrix[0])
    low = 0
    high = (rows * cols)-1

    while low <= high:
        mid = low + (high-low)//2
        mid = mid % rows
        row = mid % rows
        col = mid % cols
        if matrix[row][col] == number : return True
        elif matrix[row][col] > number : high = mid-1
        else: low = mid+1

    return False

matrix = [
        [1, 5, 10, 15],
        [19, 23, 27, 30],
        [32, 35, 39, 40],
        [42, 45, 46, 50]
    ];
number_to_find = 42
if find_in_sorted_matrix_better(matrix, number_to_find):
    print(f"{number_to_find} is present in matrix.")
else:
    print(f"{number_to_find} is not present in matrix.")