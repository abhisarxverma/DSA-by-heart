from typing import List

# Brute Force Approach
# ---------------------
# INTUITION - Sort the array then give the second element if any
# TIME COMPLEXITY - O(N LOGN) - due to sorting
# SPACE COMPLEXITY - O(N) - to store the sorted array

def find_second_largest_brute( array : List[int] ) -> int :
    sorted_array = sorted(set(array), reverse=True)
    return sorted_array[1] if len(sorted_array) > 1 else None

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