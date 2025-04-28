from typing import List

''' PROBLEM - Given the sorted array and the number, return the first and the last occurence of the number in the array using binary search '''

'''
Brute Force Approach
---------------------
LOGIC - Find the first find the first occurence and then the last occurence and then return the answer together.
TIME COMPLEXITY - O(2 LOGN) 
SPACE COMPLEXITY - O(1)
'''

def first_and_last_occurence_brute( array : List[int], number : int ) -> tuple[int]:

    # First let's find the first occurence

    first_occurence = -1

    low = 0
    high = len(array)-1
    while low <= high :
        mid = low + (high-low)//2
        if array[mid] >= number :                            # If the number is greater then we have to go left and find the number and if the number is equal to the number we are finding then also we have to go to left to find the firsr occurence of the number.
            if array[mid] == number : first_occurence = mid  # So if the number is equal to the number we are finding then save the number cause this can be the first occurence
            high = mid-1                                     # Continue search in left half                      
        else : low = mid+1                                   # Search in right half for the number

    # Maybe the number does not exist in the array
    if first_occurence == -1 : return (-1, -1)

    # Now let's find the Last occurence

    last_occurence = -1

    low = 0
    high = len(array)-1
    while low <= high :
        mid = low + (high-low)//2
        if array[mid] <= number :                            # If the number is lower than the number then we have to go to right to find the number and if the number is equal to the number then also we have to go the right to find the last occurence of the number
            if array[mid] == number: last_occurence = mid    # but before continuing the search in right half, store the current mid index cause this can be the last occurence
            low = mid+1                                      # Continue search in rigth half
        else: high = mid-1                                   # Search in left half

    return {first_occurence, last_occurence}

'''
Optimal Approach
---------------------
LOGIC -
The first occurrence of a number in a sorted array is found using lower bound, which returns:
The index of the number if it exists.
If the number isn't present, it returns the index of the next greater number.
The last occurrence is based on upper bound, which:
Always returns the index of the next greater number in the array.
So, if lower bound confirms the number is present, the last occurrence is simply upper bound - 1. 
If lower bound doesn’t find the exact number, return -1 for both occurrences.

TIME COMPLEXITY - O(2 LOGN) 
SPACE COMPLEXITY - O(1)
'''

def lower_bound( array : List[int], number : int ):
    low = 0
    high = len(array)-1
    while low <= high :
        mid = low + (high-low)//2
        if array[mid] >= number : high = mid
        else: low = mid+1
    return low

def upper_bound( array : List[int], number : int ):
    low = 0
    high = len(array)
    while low < high :
        mid = low + (high-low)//2
        if array[mid] <= number: low = mid+1
        else: high = mid
    return low

def first_and_last_occurence_optimal( array : List[int], number : int ):
    first_occurence = lower_bound(array, number)
    if array[first_occurence] != number: return {-1, -1}
    last_occurence = upper_bound(array, number)
    return (first_occurence, last_occurence-1)


array = [1, 5, 6, 6, 10, 50, 83, 83, 83, 156, 1000]
ans = first_and_last_occurence_optimal( array, 83)
print(f"Original array : {array}")
print(f"First and last occurence : {ans}")