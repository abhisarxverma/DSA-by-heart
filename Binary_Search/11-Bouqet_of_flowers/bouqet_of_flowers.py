from typing import List

'''
PROBLEM - 
Given the array of integers representing the number of the day on which the floor bloomed.
Find the minimum number of days that is required to make m bouqet of the k flowers 
given that you will make one bouqet from the contiguous days,

Example Input - [7, 3, 9, 5, 8], Bouqets = 3, Flowers_per_bouqet = 1
Example Output - 7
'''

'''
Brute Force Approach
---------------------
LOGIC - Linear Search - 
Loop from the minimum to the maximum in the array,
Have a helper function that can on giving the array, the day number and the number of the flowers we need, 
can tell us that we are able to make the bouque or not.
As we are looping from the minimum to the maximum, the first time we find any number that can give us more than or equal to the number of bouqets we need, we will return that. 

TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(1)
'''

# Helper funtion to check if we get atleast required bouqets on that day
def check_day( array : List[int], bouqets, flowers, day ):
    bouqet_count = 0
    flowers_count = 0

    for bloom_day in array:
        if bloom_day <= day:
            flowers_count += 1
            if flowers_count == flowers:
                bouqet_count += 1
                flowers_count = 0
        else : flowers_count = 0

    return bouqet_count >= bouqets

def bouqet_brute( array : List[int], bouqets : int, flowers : int ):
    low = min(array)
    high = max(array)

    for i in range(low, high+1):
        if check_day(array, bouqets, flowers, i) : return i
    
    return -1

'''
Optimal Approach
---------------------
LOGIC - Binary search - 
We here do not know that the array of the bloom days is sorted or not
But know for sure that our answer will lie in between the min and the max day in the array which is indeed sorted
So we can easily do the binary search and get our answer
So here we just have to apply the floor finding method of the binary search which we have done earlier.
We will take mid and check if the number of bouqets it gives is greater than or equal to the number of bouqets we need using the helper function that we have coded in the brute force approach
If yes then we will do the high = mid, we will not discard the mid also cause that can be the answer
And If no then simply do the low = mid+1

TIME COMPLEXITY - O(Log N) 
SPACE COMPLEXITY - O(1)
'''

def bouqet_optimal( array : List[int], bouqets : int, flowers : int ):
    low = min(array)
    high = max(array)

    while low < high : 
        mid = low + (high-low)//2
        if check_day(array, bouqets, flowers, mid) : high = mid
        else : low = mid+1

    return low if check_day(array, bouqets, flowers, low) else -1

bloom_days = [7, 3, 9, 5, 8] 
ans = bouqet_optimal(bloom_days, 3, 1)
print(f"Minimum number of days to make bouqets : {ans}")