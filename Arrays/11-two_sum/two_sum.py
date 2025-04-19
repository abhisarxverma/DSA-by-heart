from typing import List

# Given an array and a sum tell if this sum is possible by adding any two elements in an array

'''
Brute Force Approach
---------------------
LOGIC - Loop over the  array and again loop over the array leaving the outer loop index, and check if the
the pair give the required sum ,then return the vector having the index of that pair.

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
'''

def two_sum_brute( array : List[int], sum : int ) -> tuple[int]:
    n = len(array)
    if n <= 1: return (-1, -1)
    for i in range(n):
        for j in range(n):
            if i == j: continue
            if array[i] + array[j] == sum:
                return (i, j)
    
    return (-1, -1)

'''
Better Approach
---------------------
LOGIC - Using a hashmap, while looping storing the numbers visited and for the current loop number
we will check if the number exist in the hashmap , if yes, then return the current number index and 
the value of that complement number in hashmap which is it's index, if we not find any complement in 
hashmap then simply add the current loop number to hashmap with index, and pass on.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(N)
'''

def two_sum_better( array : List[int], sum : int ) -> tuple[int]:
    n = len(array)
    if n <= 1: return (-1, -1)
    map = dict()
    for index, num in enumerate(array):
        complement = sum - num
        find_complement = map.get(complement, None)
        if find_complement is not None:
            return (find_complement, index)
        map[num] = index
    
    return (-1, -1)

'''
Optimal Approach
---------------------
LOGIC - Sort the array, then take two pointers one at start and one at end, compare the sum of the numbers at the two pointers
to the target sum, if the current sum is low, then move the first pointer forward, otherwise move the last pointer backward
This is optimal but cannot return the indexes because sorting alter the indexes.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
'''

def two_sum_optimal( array : List[int], sum : int ) -> bool:
    n = len(array)
    if n <= 1: return False

    i, j = 0, n-1
    while i < j :
        current_sum = array[i] + array[j]
        if current_sum == sum: return True
        elif current_sum < sum: i+=1
        else: j-=1

    return (-1, -1)

# check
arr = [1, 5, 7, 0, 10]
sum = 15
print(two_sum_better(arr, sum))