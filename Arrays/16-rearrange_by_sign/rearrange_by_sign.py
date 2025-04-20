from typing import List

# PROBLEM - Given an array of integers, make the array aranged as first positive, then negative, then positive
# then negative, and make sure to maintain the sequence of the numbers in the original array

# Input : {-5, 2, 6, -1, 0}
# Output : {2, -5, 6, -1, 0}

'''
Brute Force Approach
---------------------
LOGIC - Take a two pointers for both positives and negatives, and increment both by two while placeing the
numbers in a new array, the pointers will act as index in which the next number should be placed

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(N)
'''

# This will only work if the number of positives and negatives are equal because of either of them are less
# then as we are incrementing the index by 2, leaving place in between, it will have a garbage value.
def rearrange_by_sign_brute( array : List[int] ):
    n = len(array)
    i = 0
    j = 1
    res = [0] * n
    for num in array:
        if num <= 0:
            res[i] = num
            i += 2
        else :
            res[j] = num
            j += 2

    array = res

'''
Better Approach
---------------------
LOGIC - Take two separate vectors for positives and negatives, put the numbers, and the merge them sequentially

TIME COMPLEXITY - O(2N)
SPACE COMPLEXITY - O(N)
'''

def rearrange_by_sign_better( array : List[int] ):
    pos = []
    neg = []

    for num in array:
        if num <= 0: pos.append(num)
        else : neg.append(num)

    i, p, n = 0, 0, 0
    while ( p < len(pos) and n < len(neg) ):
        array[i] = pos[p]
        p += 1
        array[i] = neg[n]
        n += 1

    while ( p < len(pos) ):
        array[i] = pos[p]
        p += 1
    while ( n < len(neg) ):
        array[i] = neg[n]
        n += 1

arr = [1, -3, -5, -7, 2, 0]
rearrange_by_sign_brute(arr)
print(arr)