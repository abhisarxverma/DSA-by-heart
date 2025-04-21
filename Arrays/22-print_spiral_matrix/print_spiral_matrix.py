from typing import List

# PROBLEM - Given a matrix, print the elements of the matrix in spiral order.

'''
Optimal Approach
---------------------
LOGIC - Take 4 variables to keep track of the rows and columns to print and got printed, and move in 
spiral order while updating the variables.

TIME COMPLEXITY - O(NxM)
SPACE COMPLEXITY - O(1)
'''

def print_spiral_matrix( matrix : List[List[int]] ):
    n = len(matrix)
    left = 0
    right = n-1
    top = 0
    bottom = n-1

    while top <= bottom and left <= right:

        for i in range(left, right+1):
            print(matrix[top][i], end=" ")
        top+=1

        for i in range(top, bottom+1):
            print(matrix[i][right], end=" ")
        right-=1

        if top <= bottom:
            for i in range(right, left-1, -1):
                print(matrix[bottom][i], end=" ")
            bottom-=1

        if left <= right:
            for i in range(bottom, top-1, -1):
                print(matrix[i][left], end=" ")
            left+=1


matrix = [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 11, 12],
        [13, 14, 15, 16]
]
print_spiral_matrix(matrix)
