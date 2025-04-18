
# Brute Force Approach
# ---------------------
# INTUITION - Sort the array then give the second element if any
# TIME COMPLEXITY - O(N LOGN) - due to sorting
# SPACE COMPLEXITY - O(N) - to store the sorted array

def find_second_largest_brute( array ):
    sorted_array = sorted(set(array), reverse=True)
    return sorted_array[1] if len(sorted_array) > 1 else None


# CHECK
arr = [2, 1, 5, 9, 100]
print(f"Second Largest in {arr} : {find_second_largest_brute(arr)}")
