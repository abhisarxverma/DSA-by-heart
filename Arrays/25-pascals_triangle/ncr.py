from typing import List

# PROBLEM - PASCAL'S TRIANGLE

# SUB-PROBLEM 1  - Given the row and the column number give the element on the pascal's triangle

# Formula = nCr ( n = row-1 & r = col-1 )

#    nCr = n! / r! X (n-r)!

'''
 EXAMPLE INPUT - 5, 2
 EXAMPLE OUTPUT -  10
'''

'''
Brute Approach
---------------------
LOGIC - Run loop to calculate every number in formula, n!, r! and (n-r)!

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
'''

def factorial (n : int):
    if n <= 1: return 1
    return n * factorial(n-1)

def nCr_brute( n : int, r : int ):

    n_factorial = factorial(n)
    r_factorial = factorial(r)
    n_minum_r_factorial = factorial(n-r)

    ans = n_factorial / (r_factorial * n_minum_r_factorial)
    return int(ans)

'''
Optimal Approach
---------------------
LOGIC -
    Start with res = 1, which will store the result.
    If r is greater than n - r, swap r with n - r to optimize calculations.
    Loop r times:
        Multiply res by (n - i), where i starts from 0 up to r - 1.
        Divide res by (i + 1).
    Return the final computed value.

TIME COMPLEXITY - O(r)
SPACE COMPLEXITY - O(1)
'''

def nCr_optimal( n : int, r : int ):
    res = 1
    if r > n - r: r = n - r; # Optimize by using the smaller r
    for i in range(r):
        res *= (n - i)
        res /= (i + 1)

    return int(res)

print(f"Pascal's triangle element at 6th row and 4th column : {nCr_optimal(5, 2)}")

