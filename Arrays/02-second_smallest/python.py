from typing import List

# Brute Force Approach
# ---------------------
# LOGIC - Sort the array then give the second element if any
# TIME COMPLEXITY - O(N LOGN) - due to sorting
# SPACE COMPLEXITY - O(N) - to store the sorted array

def find_second_smallest_brute( array : List[int] ) -> int :
    sorted_array = sorted(set(array), reverse=True)
    return sorted_array[-2] if len(sorted_array) > 1 else None

# Optimal Approach
# ---------------------
# LOGIC - Take the smallest and the second smallest variables and update both of them as per conditions
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