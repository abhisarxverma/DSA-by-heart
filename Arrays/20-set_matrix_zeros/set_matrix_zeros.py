from typing import List

# PROBLEM - Given a matrix of zeros and ones, make the column and row in which any of the zero is present, 0.

'''
     EXAMPLE INPUT MATRIX      EXAMPLE OUTPUT MATRIX
        1, 1, 1, 1, 1             0, 0, 1, 0, 0
        0, 1, 1, 0, 1             0, 0, 0, 0, 0
        1, 1, 1, 1, 0             0, 0, 1, 0, 0
        1, 0, 1, 1, 1             0, 0, 0, 0, 0
        1, 1, 1, 1, 1             0, 0, 1, 0, 0
'''

'''
Brute Approach
---------------------
LOGIC - Loop over rows, then loop over columns and if you find any zero, then loop over it's row and column and
mark all the numbers -1, we cannot mark them zero directly because if we do that then for the futher places, we
may uneccecarily mark the ones zeros, which will be wrong.

TIME COMPLEXITY - O(NxM x N+M)
SPACE COMPLEXITY - O(1)
'''

def set_matrix_zeros_brute( matrix : List[List[int]] ):
    n = len(matrix)
    m = len(matrix[0])

    for i in range(n):
        for j in range(m):
            if matrix[i][j] == 0:
                for x in range(n):
                    matrix[x][j] = 0
                for x in range(m):
                    matrix[i][x] = 0

    return matrix

'''
Better Approach
---------------------
LOGIC - Use a two vectors, row and cols, to save which cols and which rows to be turned zero, then at last
turn all that row and col into zero.

TIME COMPLEXITY - O(2 NxM)
SPACE COMPLEXITY - O(N+M)
'''

def set_mtrix_zeros_better( matrix : List[List[int]] ):
    n = len(matrix)
    m = len(matrix[0])

    zero_rows = [0] * n
    zero_cols = [0] * m

    for i in range(n):
        for j in range(m):
            if matrix[i][j] == 0:
                zero_cols[j] = 1
                zero_rows[i] = 1

    for i in range(n):
        for j in range(m):
            if zero_cols[j] == 1 or zero_rows[i] == 1:
                matrix[i][j] == 0

    return matrix


'''
Optimal Approach
---------------------
LOGIC - store which rows and which columsn to be made zeros in the first row and the first column itself,
then by checking the first row and first column, make the rest of the matrix 0, and at last, first check if the
first column of the first row is zero, if yes then make the first row zero, and then check if the first col to be 
made zero which we have in the col0 variable, if yes then make the first col 0.

TIME COMPLEXITY - O(2 NxM) = O(NxM)
SPACE COMPLEXITY - O(1)
'''

def set_matrix_zeros_optimal( matrix : List[List[int]] ):
    n = len(matrix)
    m = len(matrix[0])

    col0 = False

    for i in range(n):
        for j in range(m):
            if matrix[i][j] == 0:
                matrix[i][0] = 0
                if j == 0: col0 = True
                else: matrix[0][j] = 0

    for i in range(1, n):
        for j in range(1, m):
            if matrix[0][j] == 0 or matrix[i][0]:
                matrix[i][j] == 0

    if matrix[0][0] == 0:
        for i in range(m):
            matrix[0][m] = 0

    if col0:
        for i in range(n):
            matrix[n][0] = 0

    return matrix


matrix = [
        [ 1, 1, 1, 1, 1 ],
        [ 0, 1, 1, 0, 1 ],
        [ 1, 1, 1, 1, 0 ],
        [ 1, 0, 1, 1, 1 ],
        [ 1, 1, 1, 1, 1 ]
]
result = set_matrix_zeros_brute(matrix)
for i in range(len(result)):
    for j in range(len(result[0])):
        print(matrix[i][j], end=" ")
    print()