from typing import List

# PROBLEM - Given an array, return the array of elements that who has not element on the right greater than them.

# Input : {5, 2, 9, 7, 3}
# Output : {9, 7, 3}

'''
Brute Approach
---------------------
LOGIC - Loop over the array, and then loop over the array on the right of them, if you find any element greater then stop and
if not, add it to the result array

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
'''

def find_leaders_brute( array : List[int] ) -> List[int] :
    n = len(array)
    leaders = []
    for i in range(n):
        for j in range(i+1, n):
            if array[j] > array[i] : break
        else: leaders.append(array[i])
    
    return leaders

'''
Optimal Approach
---------------------
LOGIC - If you think carefully, the leaders are the numbers which are greater than the max on the right.
so iterate from the right, and store the max number, if the current number is greater than the max then
add it to the result array. else pass.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
'''

def find_leaders_optimal( array : List[int] ) -> List[int] :
    n = len(array)
    max = float("-inf")
    leaders = []
    for i in range(n-1, -1, -1):
        if array[i] > max:
            leaders.append(array[i])
            max = array[i]

    return leaders

arr = [5, 2, 9, 7, 3]
leaders = find_leaders_optimal(arr)
print(f"Leaders in {arr} : {leaders}")