from typing import List

'''
PROBLEM - Given an array of integers and a threshold number, find the minimum divisor that on dividing and taking ceil to every element in the array and summing them give the number lesser or equal to threshold

EXAMPLE INPUT - [50, 18, 28, 82, 25], threshold = 20
EXAMPLE OUTPUT - 12
'''

'''
Brute Force Approach
---------------------
LOGIC - Linear Search 
We will loop from 1 to max in the array
Why 1, cause the if the threshold is 0 then we will have the integer divison by 0 error so we will handle that case at first
Why max in array, cause on and after max, the sum of the ceils will be always be the same as the length of the array, or near to it but will not increase 
so if there is any divisor that can give the sum less than or equal to the threshold that can be the max itself or below not above that


TIME COMPLEXITY - O(N x Max(array)) 
SPACE COMPLEXITY - O(1)
'''

def check_sum(array: List[int], threshold : int, divisor : int ):
    ceil_sum = sum([(num + divisor - 1)//divisor for num in array])
    return ceil_sum <= threshold

def minimum_divisor_brute( array : List[int], threshold : int ):
    if threshold <= 0: return 0

    low = 1
    high = max(array)

    for i in range(low, high+1):
        if check_sum(array, threshold, i): return i
    
    return -1

'''
Optimal Approach
---------------------
LOGIC - Binary search
Why Binary search? We are not sure that the array given to us will be sorted, but we are sure that the answer will lie in between the 1 and the max in the array
So we will do binary search in that search space
If with the mid, the sum is greater than the threshold we will find more bigger divisor and for that we will go to the right part
and if the sum is less than or eqal to the threshold, we will save the mid and find more closer answer so we will go the left part

TIME COMPLEXITY - O(Log Max(array) x N) 
SPACE COMPLEXITY - O(1)
'''

def minimum_divisor_optimal( array : List[int], threshold : int ):
    if threshold <= 0 : return 0

    low = 1
    high = max(array)

    while low < high:
        mid = low + (high-low)//2

        if check_sum(array, threshold, mid) : high = mid
        else: low = mid+1

    if check_sum(array, threshold, low) : return low
    else : return -1


# check
array = [50, 18, 28, 82, 25]
threshold = 20
ans = minimum_divisor_optimal(array, threshold)
print(f"Minimum Divisor for {array} for threshold {threshold} : {ans}")