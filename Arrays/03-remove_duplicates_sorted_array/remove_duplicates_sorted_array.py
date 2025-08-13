from typing import List

# Brute Force Approach
# ---------------------
# INTUITION - use a set to store the seen numbers and if the number is not seen then add that into vector
# TIME COMPLEXITY - O(N)
# SPACE COMPLEXITY - O(2N) - set and result vector

def remove_duplicates_brute( array : List[int] ) -> List[int] :
    if not array or len(array) == 1: return array
    seen = set()
    res = []
    for number in array:
        if number not in seen:
            seen.add(number)
            res.append(number)

    return res

# Better Approach
# ---------------------
# INTUITION - create a new res array for answer, sort the given array and iterate over that, if the number not equal to the last number in the res array then push it in res array else pass.
# TIME COMPLEXITY - O(LogN + N) - O(LogN) to sort and O(N) to iterate over array to check for duplicates
# SPACE COMPLEXITY - O(N) - result vector to return, otherwise O(1)

def remove_duplicates_better( array : List[int] ) -> List[int] :
    if not array or len(array) == 1: return array
    array = sorted(array)
    res = []
    for number in array:
        if not res or res[-1] != number:
            res.append(number)

    return res

# Optimal Approach
# ---------------------
# INTUITION - Take one pointer back and iterate over the array, if the current number is not equal to the number at the back pointer index
# then increment the back index by 1 and make that number the current number else passon.
# TIME COMPLEXITY - O(N)
# SPACE COMPLEXITY - O(1)

def remove_duplicates_optimal( array : List[int] ) -> List[int] :
    if not array or len(array) == 1: return array
    back = 0
    for number in array[1:]:
        if array[back] != number:
            back+=1
            array[back] = number
    return array[:back+1]
        
        
# check
arr = [1, 1, 2, 2, 2, 3, 0, 4, 4, 4, 4, 0,4, 9, 9]
print(remove_duplicates_better(arr))