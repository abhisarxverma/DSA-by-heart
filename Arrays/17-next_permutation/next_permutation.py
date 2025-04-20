from typing import List

# PROBLEM - Given an array, find the next permutation of the array.

# Input : {5, 2, 9, 7, 3}
# Output : {5, 3, 2, 7, 9}

'''
Optimal Approach
---------------------
LOGIC - 

Traverse the array from right to left and locate the first number that is smaller than its next number.
Store its index as the breakpoint, since the next permutation will change from this position.
Find the smallest greater number:
Search for the smallest number greater than the breakpoint in the right portion of the array.
Swap this number with the breakpoint value to ensure the permutation moves to the next lexicographical order.
Reverse the right part:
Since the right part of the breakpoint was in descending order, reverse it to convert it into the smallest possible arrangement.
This ensures the next permutation is correctly formed while maintaining lexicographical order. 🚀

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
'''

def next_permutation( array : List[int] ):
    n = len(array)

    index = -1
    for i in range(n-2, -1, -1):
        if array[i] < array[i+1] : 
            index = i
            break
    
    if index == -1: return array[::-1]

    for i in range(n-1, index, -1):
        if array[i] > array[index]:
            temp = array[i]
            array[i] = array[index]
            array[index] = temp
            break

    array[index+1:] = reversed(array[index+1:])
    return array

#check 
arr = [5, 2, 9, 7, 3]
next = next_permutation(arr)
print(next)
