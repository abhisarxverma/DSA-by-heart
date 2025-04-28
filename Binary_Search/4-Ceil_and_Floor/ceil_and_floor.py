from typing import List

''' CEIL IMPLEMENTATION USING BINARY SEARCH '''

''' 
What is Ceil?

Ceil is the function that on giving the array and the number of which ceil is to be found
returns the number if it itself is present and if not then returns the next greater number in array
and if the no number is greater in the array then it returns the size of the array

[ SAME AS LOWER BOUND ]
'''

def ceil( array : List[int], number : int ):

    # Implement the lower bound
    low = 0
    high = array.size()

    while low < high:
        mid = low + (high-low)//2
        if array[mid] >= number: high = mid
        else: low = mid+1

    return low

''' FLOOR IMPLEMENTATION USING BINARY SEARCH '''

''' 
What is Floor?

Foor is the function that on giving the array and the number of which the floor is to be found
returns the number itself if it is present, and if the number is not present, then returns the 
next shorter number in the array and if no number is shorter then returns the -1
'''

def floor( array : List[int], number : int ):
    low = 0
    high = array.size()-1
    ans = -1

    while low <= high:
        mid = low + (high-low)//2
        if array[mid] > number : high = mid-1
        else:
            ans = mid
            low = mid-1

    return ans

array = [1, 5, 6, 10, 50, 100]
ans = floor(array, 55)
print(f"Ans : {ans}")