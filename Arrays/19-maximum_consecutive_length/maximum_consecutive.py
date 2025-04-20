from typing import List

# PROBLEM - Find the maximum length of a consecutive sequence that can be formed from the elements of the array

# Input : {5, 100, 4, 101, 102, 99, 3}
# Output : 4 [99, 100, 101, 102]

'''
Brute Approach
---------------------
LOGIC - loop every element, and search and increment the array till you do not find the next consecutive number
update the max_length if you found greater length of consecutive sequence.

TIME COMPLEXITY - O(N^2) nearly
SPACE COMPLEXITY - O(1)
'''

def maximum_consecutive_brute( array : List[int] ):
    n = len(array)
    if n == 0: return 0
    max_length = 0
    for num in array:
        current_length = 1
        next_num = num+1

        while next_num in array:
            current_length += 1
            next_num += 1

        max_length = max(max_length, current_length)

    return max_length


'''
Better Approach
---------------------
LOGIC - Sort the array, take a variable to store the previous number that we should have to make a consecutive sequence,
while iterating, check if the current number - 1, is equal to the last smaller this means that we have that number, so increase
the count, and if we encounter any duplicate to the last smaller we will pass it, if we find any number not equal to the 
last smaller we will again make the count 1 and make that number the last smaller.

TIME COMPLEXITY - O(N log N) 
SPACE COMPLEXITY - O(1)
'''

def maximum_consecutive_better( array : List[int] ):
    n = len(array)
    if n == 0 : return 0
    array = sorted(array)
    longest = 1
    temp_count = 0
    lastSmaller = float("-inf")
    for num in array:
        if lastSmaller == num-1:
            temp_count += 1
            lastSmaller = num
        elif lastSmaller != num:
            temp_count = 1
            lastSmaller = num
        longest = max(longest, temp_count)

    return longest


'''
Optimal Approach
---------------------
LOGIC - Take a set, store all the numbers in it, then loop over the array, check if the number does not have a 
consecutive lesser, then it may be the first number of the consecutive sequence then go ahead and find the longest
length of the consecutive sequenct that number gives.

TIME COMPLEXITY - O(3N) = O(N) 
SPACE COMPLEXITY - O(N) set
'''

def maximum_consecutive_optimal( array : List[int] ):
    n = len(array)
    if n == 0 : return 0
    st = set(num for num in array)
    longest = 1

    for num in array:
        if not num-1 in st:
            count = 1
            while num+count in st:
                count+=1
            longest = max(longest, count)
        
    return longest

arr = [5, 100, 4, 101, 102, 99, 3]
longest = maximum_consecutive_optimal(arr)
print(f"Maximum consecutive length in {arr} : { longest }")
