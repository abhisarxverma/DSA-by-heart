from typing import List

# Given an array with numbers which are apprearing twice in order but one number is alone find that number
# { 1, 1, 2, 2, 3, 4, 4 }

'''
Brute Force Approach
---------------------
LOGIC - Loop over the array taking two steps and check if the next number is equal to the current number if not return that number

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
'''

def find_single_number( array : List[int] ):
    n = len(array)
    if n == 0: return -1
    elif n == 1: return array[0]
    for i in range(0, n, 2):
        if array[i] != array[i+1] : return array[i]

    return -1

'''
Optimal Approach
---------------------
LOGIC - XOR concept, if you XOR same numbers the result will be 0 and if you XOR a number with zero, you will get
the number itself. So if you do XOR of the array, the numbers will cancel out and the single number will be left out.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
'''

def find_single_number_xor( array : List[int] ):
    n = len(array)
    if n == 0: return -1
    elif n == 1 : return array[0]
    xor = 0
    for num in array:
        xor ^= num
    return xor