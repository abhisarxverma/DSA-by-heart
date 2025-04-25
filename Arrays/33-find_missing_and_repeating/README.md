# PROBLEM - Given an interger 'n' and an array of size of, which should have natural number from 1 to n
 but one number is missing and in place of that integer another integer is repeating, so find both the missing and repeating number.

### EXAMPLE INPUT - {8, 6, 1, 7, 5, 2, 3, 8}, n = 8
### EXAMPLE OUTPUT - Missing - 4, Repeating - 8


## ✅ Brute Approach

- LOGIC - Take two variables, missing and repeating, Loop over every number in array
and find the count of the number in the array by looping over again, if the count = 2,
set the repeating to the number and if the count = 0, set the missing to that number

- TIME COMPLEXITY - O(N^2) two-nested-loops
- SPACE COMPLEXITY - O(1)

## ✅ Better Approach

- LOGIC - To optimize two loops, we need to remember previous counts, so take a array of size n+1,
we will put the count of the number in hasharray at the index number. and at last loop over the hasharray
to find the missing and repeating.

- TIME COMPLEXITY - O(2N) 
- SPACE COMPLEXITY - O(N)

## ✅ More Better Approach

- LOGIC - If you do some maths, you have given the number n, which means that there should be n natural numbers in array, we can find the relation of the sum 
of n natural numbers and the current sum.

CURRENT_SUM - REPEATING + MISSING = N_SUM
MISSING = N_SUM - CURRENT_SUM + REPEATING

This means that if we find the repeating we will get the missing.
so if we sort the array and loop through it, we can find the sum and also the repeating number.

- TIME COMPLEXITY - O(N LogN) SORTING + finding repeating
- SPACE COMPLEXITY - O(1)

## ✅ Optimal Approach

- LOGIC -
    We use **sum** and **sum of squares** to compare the actual vs expected values:
    - The difference in sums gives **X - Y** (Repeating - Missing).
    - The difference in sum of squares follows the identity:  
    ***X² - Y² = (X - Y)(X + Y)***
    - Extract **X + Y** by dividing `(X² - Y²) / (X - Y)`.
    - Solve for `X` and `Y` using basic algebra.

- TIME COMPLEXITY - O(N) 
- SPACE COMPLEXITY - O(1)