from typing import List, Tuple

'''
PROBLEM - Given a matrix, and a number to find, return the row and column number of that number
Every column and every row in matrix internally sorted, but the matrix as a whole is not sorted.

EXAMPLE INPUT - 
        {1, 5, 10, 15},
        {19, 23, 32, 36},
        {32, 38, 39, 48},
        {42, 45, 46, 50}

        Number = 39

EXAMPLE OUTPUT - (2, 2)
'''

'''
Brute Force Approach
---------------------
LOGIC - Double nested loops
Loop over every row and then loop over every column
return the row and column number if found, else return (-1, -1)

TIME COMPLEXITY - O(N x M) 
SPACE COMPLEXITY - O(1)
'''

def coords_in_matrix_brute( matrix: List[List[int]], number : int ) -> Tuple[int, int]:
    rows = len(matrix)
    cols = len(matrix[0])

    for row in range(rows):
        for col in range(cols):
            if matrix[row][col] == number : return (row, col)

    return (-1, -1)


'''
Better Approach
---------------------
LOGIC - Loop over the rows, and because the row is sorted we can check that the number we are finding is in that range or not
If the number is in that range then do the binary search and find the number, also note there can be multiple rows with the range that can have the number
That's why we need to check every row with the range we need
return the row and column number if number found, else return (-1, -1)

TIME COMPLEXITY - O(N x LogM) 
SPACE COMPLEXITY - O(1)
'''

def coords_in_matrix_better( matrix: List[List[int]], number: int) -> Tuple[int, int]:
    rows = len(matrix)
    cols = len(matrix[0])

    for row in range(rows):
        low = 0
        high = cols-1
        while low <= high:
            mid = low + (high-low)//2
            if matrix[row][mid] == number: return (row, mid)
            if matrix[row][mid] > number: high = mid-1
            else : low = mid+1

    return (-1, -1);
'''
Optimal Approach
---------------------
LOGIC - We will have two variables i and j
We know that the rows and columns on itself is sorted we will take advantage of that
i will be at the top row which is 0 index of matrix
j will be at the last column of top row which is total columns-1 index
And do a while loop till the i pointer becomes equal to the total rows-1 and j pointer becomes -1
Means we will start form the top right corner of the matrix
in the loop we will check if the number at the point is the number we are finding if yes return that row and column index
And if the number at that point is greater than the number we are finding, then this means that all the numbers in that column further are greater
Hence we will discard that column completely and search in one column before
But also if the number at that point is smaller than the number we are finding then this means that all the numbers in that row before are smaller 
Hence we will discard that row completely and search in the next row 
We will repeat this process and eventually if number is present we will get that.

TIME COMPLEXITY - O(N + M) 
SPACE COMPLEXITY - O(1)
'''

def coords_in_matrix_optimal( matrix: List[List[int]], number: int ) -> Tuple[int, int]:
    rows = len(matrix)
    cols = len(matrix[0])

    i = 0
    j = cols-1

    while i < rows and j >= 0:
        if matrix[i][j] == number : return (i, j)
        elif matrix[i][j] > number : j-=1
        else : i+=1

    return (-1, -1)


matrix = [
        [1, 5, 10, 15],
        [19, 23, 32, 36],
        [32, 38, 39, 48],
        [42, 45, 46, 50]
    ];
number_to_find = 36;
ans = coords_in_matrix_optimal(matrix, number_to_find)
if ans[0] == -1: print(f"{number_to_find} is not in the matrix")
else : print(f"Coords of {number_to_find} are {ans}")