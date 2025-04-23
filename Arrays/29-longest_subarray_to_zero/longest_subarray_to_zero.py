from typing import List

'''
 PROBLEM - Given an array of integers, return the longest length of the contiguous subarray that sum 0.

 EXAMPLE INPUT - -3, 7, 2, -2, -7 
 EXAMPLE OUTPUT - 4
'''

'''
Brute Approach
---------------------
LOGIC - Take a final length variable and Loop over the array , then loop over the right part of the current number in first array, if you find the 
sum 0, update the final length if greater.

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
'''

def longest_subarray_to_zero_brute( array : List[int] ):
    n = len(array)
    final_length = 0
    for i in range(n):
        sum = array[i]
        for j in range(i+1, n):
            sum += array[j]
            if sum == 0:
                final_length = max(j-i+1, final_length)

    return final_length

'''
Optimal Approach
---------------------
LOGIC - 
Use a hashmap to store prefix sums while looping over the array. The subarray sum can be zero in two cases:
Direct zero sum: If the prefix sum itself becomes 0, the subarray length is index + 1.
Previously seen prefix sum: If the prefix sum appears in the hashmap, removing the earlier portion leads to a zero-sum subarray. The length in this case is current index - stored index.
Update the final length if a longer subarray is found, while storing indices of prefix sums for future reference. 🚀

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(N) hashmap
'''

def longest_subarray_to_zero_optimal( array : List[int] ):
    n = len(array)
    prefix_sum = 0
    final_length = 0
    map = dict()
    for i in range(n):
        prefix_sum += array[i]
        if prefix_sum == 0: final_length = max(final_length, i+1)
        elif prefix_sum in map: final_length = max(i - map[prefix_sum], final_length)
        map[prefix_sum] = i

    return final_length

array = [-3, 7, 2, -2, -7 ]
longest = longest_subarray_to_zero_optimal(array)
print(f"Longest subarray length to sum 0 : {longest}")