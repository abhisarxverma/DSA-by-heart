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
        
# check
arr = [1, 1, 2, 2, 2, 3, 4, 4, 4, 4 ,4, 9, 9]
print(remove_duplicates_brute(arr))