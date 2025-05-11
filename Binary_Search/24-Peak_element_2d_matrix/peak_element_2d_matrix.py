from typing import List

'''
PROBLEM - Given a matrix, in which every 2 elements are different, and the rows and columns are not sorted,
Also, you can assume that the border of the matrix is -1. This means that you can assume that the number next or before to the numbers at end are -1.
Find the greatest Peak element and return that.

EXAMPLE INPUT - 
        {1, 3, 4, 5},
        {19, 23, 32, 36},
        {48, 50, 38, 32},
        {42, 45, 46, 50}

EXAMPLE OUTPUT - 50
'''

'''
Brute Force Approach
---------------------
LOGIC - Double nested Looping over rows and columns
Loop over rows and then loop over the columns
if you find a number which is greater than both of its side number in that row
then return the number

TIME COMPLEXITY - O(N x M) 
SPACE COMPLEXITY - O(1)
'''

def peak_element_2d_matrix_brute( matrix: List[List[int]] ):
    rows = matrix.size()
    cols = matrix[0].size()
    peak_element = -1

    for row in range(rows):
        for col in range(cols):
            if (col == 0 or matrix[row][col] > matrix[row][col-1]) and (col == cols-1 or matrix[row][col] > matrix[row][col+1]) : peak_element = matrix[row][col]

    return peak_element

'''
Optimal Approach
---------------------
LOGIC - Binary search peak element method
The logic here is based in the normal peak element algorithm of binary search
In the normal prodecure we tried to go to the right if the mid is in the ascending portion
And we tried to go to the left if the mid is in the descending portion.
Why? cause if there is no peak element in array, if the array is ascending the last number will always be the peak element
and if the array is descending the first number will always be the peak element and we try to go that direction.
But, here one condition added to this normal peak element search is that the peak element must also be greater than the upper and lower numbers
So we will have a helper function that will give us the index of the largest number in any column given
While doing the binary search on the columns we will pass the mid to the function and get the index of the largest number
Taking the largest number in column already solves the half the problem.
Now we will do the same peak element search thing, we will go right or left according to the ascending or descending.
This will give us the peak element, cause alreay we are first going to the number in column that is greater than both of it's upper and lower number
and we are trying to just find from all the maximums from all the columns the number which is also greater than the left and right numbers.

TIME COMPLEXITY - O(N x LogM) 
SPACE COMPLEXITY - O(1)
'''

def column_max_index( matrix: List[List[int]], col: int ):
    rows = len(matrix)
    max_number = float("-inf")
    max_index = -1

    for row in rows:
        if matrix[row][col] > max_number :
            max_number = matrix[row][col]
            max_index = row

    return max_index

def peak_element_2d_matrix_optimal( matrix: List[List[int]] ):
    rows = len(matrix)
    cols = len(matrix[0])
    low = 0
    high = cols-1

    while low <= high:
        mid = low + (high-low)/2
        max_index = column_max_index(matrix, mid)
        element = matrix[max_index][mid]
        left = matrix[max_index-1][mid] if max_index-1 >= 0 else -1
        right = matrix[max_index+1][mid] if max_index+1 < cols else -1
        if element > left and element > right : return element
        elif left > element : high = mid-1
        elif right > element : low = mid+1

    return -1

matrix = [
        [1, 3, 4, 5],
        [19, 23, 32, 36],
        [48, 50, 38, 32],
        [42, 45, 46, 50]
];
matrix2 = [
        [1],
        [4],
        [2],
        [5],
        [3]
    ]

peak_element = peak_element_2d_matrix_optimal(matrix)
print(f"Peak element : {peak_element}")