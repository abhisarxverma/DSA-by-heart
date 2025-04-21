from typing import List

# PROBLEM - Given the row number give the full pascal's triangle up to that row

# EXAMPLE INPUT - 4
# EXAMPLE OUTPUT 
'''
           1 
          1 1 
         1 2 1 
        1 3 3 1 
'''

'''
Brute Approach
---------------------
LOGIC - Loop for the n times which is the number of rows and for every iteration, calculate the 
number at that position using the ncr and add it to the result vector.

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(N^2) to return the triangle
'''

def nCr_optimal(n:int, r:int):
    res = 1
    if r > n-r: r = n-r
    for i in range(r):
        res *= (n-i)
        res /= (i+1)
    return int(res)

def create_pascals_traingle_brute( n : int ):
    res = []
    for i in range(n):
        row = []
        for j in range(i+1):
            row.append(nCr_optimal(i, j))
        res.append(row)
    
    return res

'''
Optimal Approach
---------------------
LOGIC - Loop for the n times which is the number of rows, and for each of that iteration, create the 
row using the optimal approach to create the row in the O(n) times.

TIME COMPLEXITY - O(N^2) same as brute but less redundant operations
SPACE COMPLEXITY - O(N^2) to return the triangle
'''

def row_in_pascals_triangle_optimal( row : int ):
    res = [1]

    for i in range(1, row):
        res.append(int(res[-1] * (row-i) / i))
    
    return res

def create_pascals_triangle_optimal( n : int ):
    res = []
    for i in range(n):
        res.append(row_in_pascals_triangle_optimal(i+1))
    return res

triangle = create_pascals_triangle_optimal(5)
for row in triangle:
    for col in row:
        print(col, end=" ")
    print()