from typing import List

# Brute Force Approach
# ---------------------
# INTUITION - Sort the array then give the second element if any
# TIME COMPLEXITY - O(N LOGN) - due to sorting
# SPACE COMPLEXITY - O(N) - to store the sorted array

def find_second_smallest_brute( array : List[int] ) -> int :
    sorted_array = sorted(set(array), reverse=True)
    return sorted_array[-2] if len(sorted_array) > 1 else None


# CHECK
arr = [2, 1, 5, 9, 100]
print(f"Second smallest in {arr} : {find_second_smallest_brute(arr)}")
