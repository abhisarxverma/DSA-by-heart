from typing import List

# PROBLEM - Given the row number give the sequence of the numbers in that row in the pascal's triangle

# EXAMPLE INPUT - 4
# EXAMPLE OUTPUT - 1 3 3 1

'''
Brute Approach
---------------------
LOGIC - Loop for the n times which is the number of rows and for every iteration, calculate the 
number at that position using the ncr and add it to the result vector.

TIME COMPLEXITY - O(Nxr)
SPACE COMPLEXITY - O(1)
'''

def nCr( n, r ):
    res = 1
    if r > n - r : r = n - r; 
    for i in range(r):
        res *= (n - i)
        res /= (i + 1)
    
    return int(res)


def row_in_pascals_triangle_brute( row ):
    res = []
    number = 1

    for i in range(row):
        res.append(nCr(row-1, i))

    return res

'''
Optimal Approach
---------------------
LOGIC - - Start with the first element 1.
-Compute each subsequent element using the previous one:
res[i] = (res[i-1] * (row - i)) / i

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
'''

def row_in_pascals_triangle_optimal( row : int ):
    res = [1]

    for i in range(1, row):
        res.append(int((res[-1] * (row-i)) / i))

    return res

row = row_in_pascals_triangle_optimal(5)
for i in row: print(i, end=" ")
print()
