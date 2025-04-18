from typing import List

# Optimal Approach
# ---------------------
# INTUITION - Take the smallest and the second smallest variables and update both of them as per conditions
# TIME COMPLEXITY - O(N)
# SPACE COMPLEXITY - O(1)

def find_second_smallest_optimal( array : List[int] ) -> int :
    smallest = float("inf")
    second_smallest = float("inf")
    for num in array:
        if num < smallest: 
            second_smallest = smallest
            smallest = num
        elif num < second_smallest and num > smallest:
            second_smallest = num
    
    return second_smallest if second_smallest != float("inf") else None

# CHECK
arr = [2]
print(f"Second smallest in {arr} : {find_second_smallest_optimal(arr)}")