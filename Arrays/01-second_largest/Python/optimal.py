from typing import List

# Optimal Approach
# ---------------------
# INTUITION - Take the largest and the second largest variables and update both of them as per conditions
# TIME COMPLEXITY - O(N)
# SPACE COMPLEXITY - O(1)

def find_second_largest_optimal( array : List[int] ) -> int :
    largest = float("-inf")
    second_largest = float("-inf")
    for num in array:
        if num > largest: 
            second_largest = largest
            largest = num
        elif num > second_largest and num < largest:
            second_largest = num
    
    return second_largest if second_largest != float("-inf") else None

# CHECK
arr = [2]
print(f"Second Largest in {arr} : {find_second_largest_optimal(arr)}")