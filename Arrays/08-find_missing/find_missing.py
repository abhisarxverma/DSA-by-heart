from typing import List

# Given an integer n and an array of size n-1, which should be having intergers from 1 to n but one number is missing find that number

'''
Brute Force Approach
---------------------
LOGIC - Loop from one to given integer and for every number loop into the given array to check if the number is present,
if not then straight return the number

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
'''

def find_missing_brute( array : List[int], n : int ) -> int:
    for i in range(1, n+1):
        for num in array:
            if i == num: break
        else:
            return i
    return -1

'''
Optimal Approach
---------------------
LOGIC - We have given the integer which is the number of first n natural numbers that must be there, but one is missing
so if we sum the array and calculate the sum that should the array have and subtract that then we can get the number missing.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
'''

def find_missing_optimal( array : List[int], n : int ) -> int:
    should_be_sum = (n*(n+1))/2
    current_sum = sum(array)
    return should_be_sum - current_sum

'''
Optimal2 Approach
---------------------
LOGIC - XOR concept, more faster calculations. do a XOR between the xor of n natural numbers and current array xor.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
'''

def find_missing_optimal_xor( array : List[int], n : int ) -> int :
    xor1 = 0
    xor2 = 0
    for index, num in enumerate(array):
        xor1 ^= num
        xor2 ^= index+1
    
    xor2 ^= n
    return xor2 ^ xor1

# check
arr = [1, 3, 4, 5, 6]
print(find_missing_optimal_xor(arr, 6))