from typing import List

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
arr = [1, 1, 2, 2, 2, 3, 4, 4, 4, 4 ,4, 9, 9]
print(remove_duplicates_optimal(arr))