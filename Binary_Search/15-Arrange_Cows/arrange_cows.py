from typing import List

'''
PROBLEM - Given an array of integers which are the stalls and the value is their position. Place the given number of cows in such a way that the minimum distance between them is the maximum distance possible for the arrangement of the given number of cows

EXAMPLE INPUT - [1, 2, 4, 8, 9], n = 3
EXAMPLE OUTPUT - 3
'''

'''
Brute Force Approach
---------------------
LOGIC - Linear search
We have to find the minimum distance between the cows that is also the maximum distance possible to place the n cows.
So we will backwards from the maximum distance stall cause we cannot place not even a single cow beyond that.
And while iterating we will check the number of the cows we are able to place with that minimum distance.
We will have a variable to count the cows_placed and a variable to store the stall in which we have placed the last cow
So that we can calculate and check if the current stall is valid to place cow according to the minimum distance.

TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(1)
'''

def arrange_cows_brute(stalls : List[int], n: int):
    stalls = sorted(stalls)

    high = stalls[-1]
    for distance in range(high, 0, -1):
        total_cows_placed = 1
        last_cow_stall = stalls[0]
        for stall in stalls[1:]:
            if stall - last_cow_stall >= distance:
                total_cows_placed += 1
                last_cow_stall = stall
        
        if total_cows_placed >= n: return distance
    
    return -1

'''
Optimal Approach
---------------------
LOGIC - Binary search
The possible minimum distances range from 1 to max(stalls) - min(stalls).
We perform binary search over this range.
Pick mid = (low + high) / 2 as the candidate minimum distance.
Try placing cows at this distance using a greedy approach (always placing the next cow at the earliest valid stall).
If cows can be placed successfully, increase low = mid + 1 (try larger distances).
Otherwise, decrease high = mid - 1 (try smaller distances).
The last valid mid before low > high gives the maximum possible minimum distance for optimal cow placement.

TIME COMPLEXITY - O(N * Log(Max-Min)) 
SPACE COMPLEXITY - O(1)
'''

# Helper function to count number of cows placed
def check_cows_placed(stalls : List[int], n: int, distance: int) :
    total_cows_placed = 1
    last_cow_stall = stalls[0]

    for stall in stalls:
        if (stall - last_cow_stall >= distance):  # Fixed comparison issue
            total_cows_placed += 1
            last_cow_stall = stall
        
        if total_cows_placed >= n : return True # Early exit for efficiency
    
    return False

def arrange_cows_optimal(stalls : List[int], n: int) :
    stalls = sorted(stalls)  # Sorting is required

    low = 1
    high = stalls[-1] - stalls[0]
    result = -1

    while (low <= high) : # Corrected binary search condition
        mid = low + (high - low) // 2

        if check_cows_placed(stalls, n, mid):
            result = mid
            low = mid + 1 # Move towards larger minimum distance
        else :
            high = mid - 1  # Reduce search space
        
    return result

stalls = [1, 2, 4, 8, 9]
cows_to_place = 3
print(f"Minimum maximum distance for stalls - {stalls} : {arrange_cows_brute(stalls, cows_to_place)}")
print(f"Minimum maximum distance for stalls - {stalls} : {arrange_cows_optimal(stalls, cows_to_place)}")