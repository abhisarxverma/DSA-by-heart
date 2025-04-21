from typing import List
# PROBLEM - Given an array of intergers and an integer k, give the total number of subarrays that give the sum k.

'''
 EXAMPLE INPUT - 5, 2, 7, -2, 9 
 EXAMPLE OUTPUT - 3
'''

'''
Brute Approach
---------------------
LOGIC - Take a variable count Loop over every element, loop over every element on the right and add it while checking if the sum
is equal to k if yes increment the count.

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
'''

def total_subarray_to_sum_k( array : List[int], k : int ):
    n = len(array)
    if n == 0 : return 0

    count = 0

    for i in range(n):
        sum = array[i]
        for j in range(i+1, n):
            sum += array[j]
            if sum == k:
                count += 1
                
    return count

'''
Optimal Approach - PREFIX SUM
------------------------------
LOGIC - Take a hashmp, and while iterating , put the sum and the number of elements that are giving that sum
to the hashmap, and also while iterating check if the hashmap contains [ current sum - k ] in it, if yes
add to the count the value from the hashmap, cause the main concept is that if you are above the required sum
and you have the sum in the storage, that means that we can remove and get the requrired sum. 

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(N) hashmap
'''

def total_subarray_sum_to_k_optimal( array : List[int] , k : int ):
    prefix_sum_map = dict()  # HashMap to store cumulative sums and their counts
    sum , count = 0, 0

    prefix_sum_map[0] = 1;  # Base case: If sum is exactly 'k' at some point, we count from start

    for num in array:
        sum += num;  # Update running sum
        
        # Check if (current_sum - k) exists in HashMap
        # This means we previously had a sum such that removing it results in sum = k
        if prefix_sum_map.get(sum-k, None) is not None:
            count += prefix_sum_map[sum - k];  # Add occurrences of that sum to count

        # Store frequency of current sum in HashMap
        prefix_sum_map[sum] = prefix_sum_map.get(sum, 0) + 1

    return count

arr = [ 5, 2, 7, -2, 9 ]
res = total_subarray_sum_to_k_optimal(arr, 7)
print(f"Total subarrays : {res}")