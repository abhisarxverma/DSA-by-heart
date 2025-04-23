from typing import List

'''
 PROBLEM - Given an array of integers, return the total number of the contiguous subarrays that give the target xor k.

 EXAMPLE INPUT - 4, 2, 2, 6, 4 , k = 6
 EXAMPLE OUTPUT - 4
'''

'''
Brute Approach
---------------------
LOGIC - Take the variable count, and loop over the array, then loop over the right side of the first loop element, 
and check the xor if equal to the target then increase the count else pass.

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
'''

def total_subarrays_to_xor_brute( array : List[int], target_xor ):
    n = len(array)
    count = 0
    for i in range(n):
        xor = array[i]
        if xor == target_xor: count+=1
        for j in range(i+1, n):
            xor ^= array[j]
            if xor == target_xor: count+=1

    return count

'''
Optimal Approach - PREFIX SUM CONCEPT
--------------------------------------
LOGIC - 
Use a hashmap to store prefix xor while looping over the array. 
Check if the there exist the number [prefix_xor ^ k] in hashmap, if yes then add in the count the value of that number in map
Update the final length if a longer subarray is found, while storing indices of prefix xor for future reference. 🚀

TIME COMPLEXITY - O(N) OR O(N logN) - hashmap operations
SPACE COMPLEXITY - O(N)
'''

def total_subarrays_to_xor_optimal( array : List[int], target_xor : int ):
    n = len(array)
    prefix_xor = 0
    count = 0
    map = dict()
    map[0] = 1 # in case if the prefix xor itself becomes the target xor then [prefix_xor ^ target_xor] will be 0, in that case also we have to increase count that's why we have to put the 0 earlier in the map
    for num in array:
        prefix_xor ^= num
        xor_not_needed = prefix_xor ^ target_xor
        if xor_not_needed in map: count += map[xor_not_needed]
        map[prefix_xor] = map.get(prefix_xor, 0) + 1
    return count


array = [4, 2, 2, 6, 4]
total = total_subarrays_to_xor_optimal(array, 6)
print(f"Total subarrays to xor : {total}")