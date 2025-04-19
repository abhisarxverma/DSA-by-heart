from typing import List

'''
Brute Force Approach
---------------------
LOGIC - Take a new list, loop the given array and store the nonzero numbers in the vector and count the number of zeros, then fill the remaining places to the zeros.
TIME COMPLEXITY - O(2N) = O(N) - due to sorting
SPACE COMPLEXITY - O(N) - new list
'''

def move_zeros_right_brute( array : List[int] ):
    n = len(array)
    if n <= 1 : return array
    res = []
    zero_count = 0
    for num in array:
        if num != 0 : res.append(num)
        else : zero_count += 1

    for i in range(zero_count):
        res.append(0)

    return res

'''
Brute-2 Approach
---------------------
LOGIC - Using the bubble sort, if any number is zero swap it with the right number, 
do this till the zero comes to the extreme right as in bubble sort the biggest number comes to the extreme right.

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
'''

def move_zeros_right_brute2( array : List[int] ):
    n = len(array)
    if n <= 1: return array
    for i in range(n-1, 0, -1):
        for j in range(i):
            if array[j] == 0: 
                temp = array[j]
                array[j] = array[j+1]
                array[j+1] = temp
    return array

'''
Better Approach
---------------------
LOGIC - Using the concept of quicksort, the right pointer 'j' will find the nonzero number 
and the left pointer 'i' will find the zero number and they will swap with each other till
they becomes equal means no zeros left. but the sequence will be distorted 

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
'''

def move_zeros_right_better( array : List[int] ):
    n = len(array)
    if n <= 1: return array
    i = 0
    j = n-1
    while True:
        while i < j and array[i] != 0 : i+=1
        while i < j and array[j] == 0 : j-=1
        if i >= j: break
        temp = array[i]
        array[i] = array[j]
        array[j] = temp
    return array

'''
Optimal Approach
---------------------
LOGIC - Two pointer approach, take two pointer and move the first pointer to the first zero, and then loop from the front of it to the end of array
if you find a non zero then as the j have the zero, swap them so that the zero will be replaced by the number, this will take all the zeros to right.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
'''

def move_zeros_right_optimal( array : List[int] ):
    n = len(array)
    if n <= 1: return array
    j = -1
    for i in range(n): # Take the j to the first zero
        if array[i] == 0:
            j = i
            break

    if j == -1: return array # No zeros

    for i in range(j+1, n):
        if array[i] != 0:
            temp = array[i]
            array[i] = array[j]
            array[j] = temp
            j += 1

    return array

# check
arr = [1, 0, 0, 5, 0, 2, 3, 0]
moved = move_zeros_right_optimal(arr)
print(moved)