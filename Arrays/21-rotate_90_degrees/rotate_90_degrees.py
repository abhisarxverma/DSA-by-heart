from typing import List

# PROBLEM - Rotate the given square matrix in a clockwise direction

''' 
    EXAMPLE INPUT MATRIX   EXAMPLE OUTPUT MATRIX
         1, 2, 3, 4            13 9 5 1 
         5, 6, 7, 8            14 10 6 2 
         9, 10, 11, 12         15 11 7 3 
         13, 14, 15, 16        16 12 8 4

'''
# helper function to print matrix after rotating to check
def print_matrix ( matrix : List[List[int]] ):
    rows = len(matrix)
    cols = len(matrix[0])
    for row in matrix:
        for col in row:
            print(col, end=" ")
        print()

'''
Brute Approach
---------------------
LOGIC - Loop over the rows, then loop over the columsn in reverse order, take a new result vector, place
the numbers at their new indexes according to the relation between the indexes - 

matrix[row][col] -> new_matrix[col][row]

TIME COMPLEXITY - O(n^2)
SPACE COMPLEXITY - O(n^2)
'''

def rotate_90_degrees_brute( matrix: List[List[int]] ):
    n = len(matrix)
    m = len(matrix[0])

    new_matrix = [[0] for _ in range(m) for _ in range(n)]
    for j in range(n):
        for i in range(n-1 , -1, -1):
            new_matrix[j][n-1-i] = matrix[i][j]

    return new_matrix


'''
optimal Approach
---------------------
LOGIC - Transpose the matrix , and then reverse every row

TIME COMPLEXITY - O(n^2) nearly
Transpose - O(n/2 * n/2) nearly
Reverse - O(n * n/2);

SPACE COMPLEXITY - O(1)
'''

def transpose_matrix( matrix : List[List[int]] ):
    n = len(matrix)
    m = len(matrix[0])
    for i in range(n):
        for j in range(i+1, m):
            matrix[i][j] = matrix[j][i]
    return matrix

def rotate_90_degrees_optimal( matrix : List[List[int]] ):
    matrix = transpose_matrix(matrix)
    n = len(matrix)
    for i in range(n):
        matrix[i] = matrix[i][::-1]
    return matrix

matrix = [
        [ 1, 2, 3, 4 ],
        [ 5, 6, 7, 8 ],
        [ 9, 10, 11, 12 ],
        [ 13, 14, 15, 16 ],
]

rotated = rotate_90_degrees_optimal(matrix)
print_matrix(rotated)