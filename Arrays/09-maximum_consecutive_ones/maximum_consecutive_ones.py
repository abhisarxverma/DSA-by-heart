from typing import List

# Given an array, find the maximum number of consecutive ones in the array

'''
Brute Force Approach
---------------------
LOGIC - Take a final_count and a temp_count, loop over the array, and store the count of the ones in a temp_count and if a number comes which
is not one then, check if the temp count is greater than the final count, if yes update the final count else pass on.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
'''

def maximum_consecutive_ones_brute( array : List[int] ):
    final_count = 0
    temp_count = 0
    for num in array:
        if num == 1: temp_count+=1
        else:
            final_count = max(final_count, temp_count)
            temp_count = 0
    return max(final_count, temp_count)