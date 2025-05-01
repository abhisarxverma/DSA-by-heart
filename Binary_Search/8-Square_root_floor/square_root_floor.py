from typing import List

'''
PROBLEM - Given an integer, find the square root if perfect square exists else give the floor square root.

Example Input - 110 | 49 | 90
Example Output - 10 | 7  | 9
'''

'''
Brute Force Approach
---------------------
LOGIC - Linear search - 
To find the floor square root using linear search, we iterate from 1 to (n/2) + 1:
Calculate the square of each number.
If the square is less than or equal to n, store the current number (potential floor square root).
If the square is greater than n, break the loop—the stored number is the final floor square root.

TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(1)
'''

def square_root_floor_brute( number : int ):
    ans = -1
    for i in range((number//2)+2):
        square = i * i
        if square <= number: ans = i
        else : break

    return ans

'''
Optimal Approach
---------------------
LOGIC -
To find the square root of a number using binary search, we search in the range 1 to (n/2) + 1:
If we find the exact square root, we return the number.
If the square is greater than n, we remove the right part.
If the square is smaller than n, we remove the left part.
At the end, high will store the floor value of the square root because we decrement high when the square exceeds n. 
The last decremented high is the correct floor square root.

TIME COMPLEXITY - O(Log N) 
SPACE COMPLEXITY - O(1)
'''

def square_root_floor( number : int ):
    low = 1
    high = (number//2)+1

    while low <= high:
        mid = low + (high-low)//2
        mid_square = mid * mid
        if mid_square == number: return mid
        elif mid_square > number: high = mid-1
        else: low = mid+1

    return high


square_root = square_root_floor(102)
print(f"Square root : {square_root}")