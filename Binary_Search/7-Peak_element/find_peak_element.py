from typing import List

'''
PROBLEM - Given an array, find the peak element and return the index of that element.
For the extremes you can assume that the number before the left extreme is -infinite and the number after the right extreme is -infinite
Peak element - The element in the array which is greater than the left number and greater than the right number.
'''

'''
Brute Force Approach
---------------------
LOGIC - Linear search- Go over the array one by one and check for the conditions and return the index if the conditions are met.
TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(1)
'''

def find_peak_element_brute( array : List[int] ):
    n = len(array)
    for i in range(n):
        if (i==0 or array[i] > array[i-1]) and (i==n-1 or array[n-1] > array[n-2]) : return i
    
    return -1

'''
Optimal Approach
---------------------
LOGIC -
The peak element in an array is the one that is greater than its neighbors. 
Since the left and right sides of the peak are sorted, we can use binary search to find it efficiently.

Understanding the Extremes:
If the array is sorted in ascending order, the peak will be at the end.
If it's sorted in descending order, the peak will be at the start.
If the array is mixed, the peak lies somewhere in between.

Binary Search Logic:
Get the mid index.
Check if mid is a peak (greater than both left and right).
If the mid is in an ascending part, move right (the peak lies ahead).
If the mid is in a descending part, move left (the peak is behind).

TIME COMPLEXITY - O(Log N) 
SPACE COMPLEXITY - O(1)
'''

def find_peak_element_optimal( array : List[int] ):    
    n = len(array)
    if n == 1: return 0
    if array[0] > array[1] : return 0
    if array[n-1] > array[n-2] : return n-1

    low = 1
    high = n-2

    while low <= high :
        mid = low + (high-low)//2
        if array[mid] > array[mid-1] and array[mid] > array[mid+1] : return mid
        if array[mid] < array[mid-1] : high = mid-1
        elif array[mid] < array[mid+1] : low = mid+1

    return -1

array = [5, 4, 3, 2, 1]
peak_element_index = find_peak_element_optimal(array)
print(f"Peak element is at index {peak_element_index}")