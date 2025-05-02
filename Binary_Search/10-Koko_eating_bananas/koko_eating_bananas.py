from typing import List

'''
PROBLEM - KOTO EATING BANANAS - Find the least possible number of the bananas that if the koto eat per hour he will eat all the bananas within the given target hour

Example Input - [3, 6, 7, 11], 8
Example Output - 4
'''

'''
Brute Force Approach
---------------------
LOGIC - Linear Search - 
    - Loop from 1 to maximum in the array
    - Using a helper function that on giving the banana array, the target hour and the current speed which we want to check can tell us that with that speed, the time which the koko will take will be under the target or exceed it.
    - Cause we are already going from lowest possible to highest possible, the first time we find the number that satisfy the constraint then we will return it.

TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(1)
'''

def check_eating_time( array: List[int], target : int , speed : int ):
    ans = 0
    for num in array:
        ceil = (num + speed - 1) / speed
        ans += ceil
        if ans > target : return 2
    if ans <= target : return 1

def koko_brute( array : List[int] , target_hour : int ):
    low = 1
    high = max(array)

    for i in range(low, high+1):
        if check_eating_time(array, target_hour, i )<= 1 : return i
    return -1

'''
Optimal Approach
---------------------
LOGIC - BINARY SEARCH -
    - According to the problem, we are given array of bananas which we are not sure is sorted.
    - but we are assure that koko can eat from 1 to the maximum number of bananas that is in the array, 
    - so the search space is sorted and hence we can easily do the Binary search and get our answer.
    - so here we simply have to find the floor using the binary search which we have done before
    - Have a helper function that can on giving the bananas array, the target hours and the current mid which will be the speed to check, can tell us that with that speed if the koko eat the bananas, surpass the target or stay within that
    - If eating the bananas with the speed of the current mid surpass the target hour then simply discard the left half and search in the right half
    - This is the trick here, that on increasing the speed, time decreases, so to reduce time we have to go to the right half
    - And if eating bananas with the speed of the current mid stays less than or equal to the target hour, then save that mid and search for more smaller number that stays under the target hour.

TIME COMPLEXITY - O(Log N) 
SPACE COMPLEXITY - O(1)
'''

def koko_optimal ( array : List[int], target_hour : int ):
    low = 1
    high = max(array)

    while low < high :
        mid = low + (high-low)/2
        
        if check_eating_time(array, target_hour, mid) == 2 : low = mid+1
        else : high = mid

    return low

array = [3, 6, 7, 11]
ans = koko_optimal( array, 8 )
print(f"Ans : {ans}")