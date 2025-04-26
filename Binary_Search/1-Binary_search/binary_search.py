from typing import List

'''
What is Binary Search?

Binary Search is the method though which we can find any element in sorted array of any type in LogN time.
This algorithm can be applied to any sorted array of any type of elements, it will give the result.

INTUITION - 
Keep in mind the array is sorted. so if the 'k' is shorter to one number it will be shorter to all the numbers in right and vice-versa.
Go the middle of the array compare the number 'k' you want to find to the middle number. 
if the 'k' is shorter than the middle then you can discard the right half of the array. Now the search space is left half
and if the 'k' is greater than the middle then you can discard the left half of the array. Now the search space is right half
Now repeat this same process till the search space gets to 1 and check that also.
Till that you should find your number, if not then the number is not in the array.
'''

'''
BINARY SEARCH IMPLEMENTATION
'''

''' ITERATIVE '''

def binary_search( array : List[int], number : int ):
    low, high = 0, len(array)-1
    while low <= high:
        mid = low + (high-low)/2
        if array[mid] == number : return mid
        elif number < array[mid] : high = mid-1 # Number is in the left half
        else: low = mid+1                       # Number is in the right half

    return -1

''' RECURSIVE '''

def binary_search_recursive( array : List[int], number : int, low : int, high : int ):
    if low > high: return -1
    mid = low + (high-low)//2
    if array[mid] == number: return mid
    elif number < array[mid] : return binary_search_recursive(array, number, low, mid-1 )
    else : return binary_search_recursive( array, number, mid+1, high )


vec = [-50, 1, 5, 6, 20, 99]
number_to_find = -50
index = binary_search_recursive(vec, number_to_find, 0, len(vec)-1)
print(f"{number_to_find} at {index}" if index != -1 else f"{number_to_find} if not in array.")
