from typing import List

# PROBLEM - Given an array of integers, find the and return all the triplets that have the sum 0

'''
 EXAMPLE INPUT - 3, 5, -1, 5, -10, -8, 5, 0
 EXAMPLE OUTPUT - [3, 5, -8], [5, -10, 5]
'''

'''
Brute Approach
---------------------
LOGIC - Take a set, loop over the array in the nested three times, and if you find the sum of a
triplet equal to the zero, then sort it and put it in set so that the set can check if the same
triplet is not entered twice. Then at last put the triplets from the set to the vector and return.

TIME COMPLEXITY - O(N^3 + LogM) = O(N^3)
SPACE COMPLEXITY - O(N^3) Worst case : Set will store all the triplets from the array
'''

def three_sum_brute( array : List[int] ):
    n = len(array)
    unique_triplets = set()
    for i in range(n):
        for j in range(i+1, n):
            for k in range(j+1, n):
                sum = array[i] + array[j] + array[k]
                if sum == 0:
                    triplet = sorted(array[i], array[j], array[k])
                    unique_triplets.add(triplet)
    res = list(unique_triplets)
    return res

'''
Better Approach
------------------------------------
LOGIC - Loop over the array, then loop over the second time, but before that take a set
to store the visited numbers in the second loop, so while in the second loop check the set
for the 0 - (array[j] + array[k])), if yes this means we have a triplet, store it.

TIME COMPLEXITY - O(N^2 + LogM) = O(N^2)
SPACE COMPLEXITY - O(N^3) Worst case : Set will store all the triplets from the array
'''

def three_sum_better ( array : List[int] ):
    n = len(array)
    unique_triplets = set()
    for i in range(n):
        numbers = set()
        for j in range(i+1, n):
            remaining = -(array[i] + array[j])
            if remaining in numbers:
                triplet = sorted(array[i], array[j], remaining)
                unique_triplets.add(triplet)
            numbers.add(array[j])

    res = list(unique_triplets)
    return res

'''
Optimal Approach
------------------------------------
LOGIC - Sort the array, then take the three pointers, put one at start and one at end
and one at the next to the start pointer, if the sum is less, then move the middle 
pointer right else left, and with that move the start and the end pointers skipping duplicates.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(N^3) Worst case : Set will store all the triplets from the array
'''

def three_sum_optimal( array : List[int] ):
    n = len(array)
    unique_triplets = set()
    for i in range(n):
        if i > 0 and array[i] == array[i-1]: continue
        j = i+1
        k = n-1
        while j < k:
            sum = array[i] + array[j] + array[k]
            if sum < 0: j+=1
            elif sum > 0 : k-=1
            else:
                triplet = sorted(array[i], array[j], array[k])
                unique_triplets.add(triplet)
                j+=1
                k-=1
                while j < k and array[j] == array[j-1]: j+=1
                while j < k and array[k] == array[k+1]: k-=1

        return list(unique_triplets)


array = [3, 5, -1, 5, -10, -8, 5, 0]
ans = three_sum_optimal(array)
for triplet in ans:
    for number in triplet:
        print(number, end=" ")
    print()