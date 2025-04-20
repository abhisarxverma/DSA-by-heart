from typing import List

# MAJORITY ELEMENT - find the element that appears in the array more than half the size of the array

'''
Brute Force Approach
---------------------
LOGIC - Loop the array, and for every element, loop again to calculate it's count, if it is greater than
half the size of the array, return it else return -1;

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
'''

def majority_element_brute( array : List[int] ):
    n = len(array)
    target_count = (n//2)+1
    for num in array:
        count = 0
        for num2 in array:
            if num == num2: count += 1
        if count >= target_count: return num
    
    return -1

'''
Better Approach
---------------------
LOGIC - Using a hashmap, to store the count while iterating, and to optimize a little, just after increasing count
of a number, we have to check if the target is met, else pass.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(N) hashmap
'''

def majority_element_better( array : List[int] ):
    n = len(array)
    map = dict()
    for num in array:
        if num in map: map[num] += 1
        else: map[num] = 1
        if map[num] >= (n//2)+1 : return num

    return -1

'''
Optimal Approach
---------------------
LOGIC - Boore-Moyre's voting algorithm, the concept is if a number has count greater than half the size
of array, then while iterating and increasing the count if we find the same number and descreasing the
count if we find other than that, then at last the majority number should be remaining, cause it is one extra than
half the size so no other can cancel out it.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
'''

def majority_element_optimal( array : List[int] ):
    n = len(array)
    number = array[0]
    count = 1
    for num in array[1:]:
        if count == 0:
            number = num
            count = 1
        elif num == number:
            count += 1
        else: count -= 1
    
    # Double check in case of majority element may or may not exist
    count2 = 0
    for num in array:
        if num == number:
            count2 += 1
    if count2 >= (n//2)+1: return number

    return -1

# check
arr = [1, 2, 2, 3, 2, 0, 2, 5, 2]
ans = majority_element_optimal(arr)
print(f"Majority element : {ans}")