from typing import List

'''
What is Lower Bound?

Lower bound is the type of binary search which returns the index of the number if it is int array,
and if the number is not in the array then it finds and give the next largest number in the array,
and if number itself is not present and no number is largest to the number it returns the size of the array which is not a valid index.

LOWER BOUND - IMPLEMENTATION
'''

''' ITERATIVE 1 '''

def lower_bound( array : List[int], number : int ):
    low = 0
    high = len(array)-1
    ans = len(array)                  # To store the answer, and initialize this with array's size so that if no element is greater than number to find, then it will return the size

    while low <= high :
        mid = low + (high-low)/2
        if array[mid] >= number :
            ans = mid;                # Store the current number, but we need to check more on left side cause if this is the number itself, this may not be the first occurence and if it is greater than the number, this may not be the next greater
            high = mid-1;             # Try to find the answer in the left again
        else: low = mid+1;            # Answer is in the right half

    return ans; # Return the answer


''' ITERATIVE 2 '''  

def lower_bound_2( array : List[int], number : int ):
    low = 0
    high = len(array)
    while low < high :
        mid = low + (high-low)//2
        if array[mid] >= number:        # This element can be the answer, cause either it is itself the number to find
            high = mid                  # So in this case we have to find the first occurence, for which we have to search left
                                        # and if the number is not in the array we have to return the next greater , which lies in the left
                                        # also this can also be the next greater and that's why we have to keep it in the search space and that's why
                                        # we will do high = mid, rather than high = mid-1
       
        else: low = mid+1 # The answer is in the right half

    return high # The high will have the answer

''' RECURSIVE '''

def lower_bound_recursive( array : List[int], number : int, low : int, high : int ):
    if low >= high: return low
    mid = low + (high-low)//2
    if array[mid] >= number : return lower_bound_recursive( array, number, low, mid )
    else: return lower_bound_recursive( array, number, mid+1, high)

array = [1, 5, 9, 10, 32, 55]
ans = lower_bound_recursive(array, 100, 0, len(array))
print(f"Ans : {ans}")