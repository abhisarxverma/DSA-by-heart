from typing import List

# PROBLEM - MAXIMUM SUBARRAY SUM - Find the maximum sum that can be taken by summing any contiguous part of the array

'''
Brute Force Approach
---------------------
LOGIC - Loop over the array, and for every number, loop over the array next to it, and store the maximum sum
and return the greatest.

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
'''

def maximum_sum_subarray_brute( array : List[int] ):
    n = len(array)
    final_sum = float("-inf")
    for i in range(n):
        temp_sum = array[i]
        for j in range(i+1, n):
            temp_sum += array[j]
            final_sum = max(final_sum, temp_sum)

    return final_sum

'''
Optimal Approach
---------------------
LOGIC - KADANE'S ALGORITHM - While looping in the array, store the sum, if the sum drops to negative
then turn it back to zero, and if the sum is positive then keep it increasing

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
'''

def maximum_sum_subarray_optimal( array : List[int] ):
    n = len(array)
    final_sum = float("-inf")
    temp_sum = 0
    for num in array:
        temp_sum += num
        final_sum = max(final_sum, temp_sum)
        if temp_sum < 0: temp_sum = 0
    return final_sum

#check

arr = [1, 5, 9, 6, -10]
ans = maximum_sum_subarray_optimal(arr)
print(f"Maximum sum : {ans}")