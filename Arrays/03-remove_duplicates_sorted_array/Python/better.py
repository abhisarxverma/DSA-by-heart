from typing import List

# Better Approach
# ---------------------
# INTUITION - create a new res array, and iterate over the original array, if the number not equal to the last number in the res array then push it in res array else pass.
# TIME COMPLEXITY - O(N)
# SPACE COMPLEXITY - O(N) - result vector

def remove_duplicates_better( array : List[int] ) -> List[int] :
    if not array or len(array) == 1: return array
    res = []
    for number in array:
        if not res or res[-1] != number:
            res.append(number)

    return res
        
# check
arr = [1, 1, 2, 2, 2, 3, 4, 4, 4, 4 ,4, 9, 9]
print(remove_duplicates_better(arr))