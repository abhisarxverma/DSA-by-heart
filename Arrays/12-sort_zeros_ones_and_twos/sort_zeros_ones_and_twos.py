from typing import List

'''
Brute Force Approach
---------------------
LOGIC - Use any sorting method like bubble sort O(n^2), merge sort (n log n), quick sort (n^2), selection sort(n^2), insertion sort(n^2)
I have used the selection sort.

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
'''

def sort_zeros_ones_twos_brute( array : List[int] ):
    n = len(array)
    for i in range(n):
        min = i
        for j in range(i+1, n):
            if array[j] < array[min]:
                min = j
        if min != i:
            temp = array[i]
            array[i] = array[min]
            array[min] = temp
    return array


'''
Better Approach
---------------------
LOGIC - Count the number of zeros, ones and twos and place them one by one

TIME COMPLEXITY - O(2N) = O(N)
SPACE COMPLEXITY - O(1)
'''

def sort_zeros_ones_twos_better( array : List[int] ):
    n = len(array)
    zero_count = 0
    one_count = 0
    two_count = 0
    for num in array:
        if num == 0: zero_count+=1
        elif num == 1: one_count+=1
        else :two_count+=1

    res = []
    for i in range(n):
        if zero_count:
            res.append(0)
            zero_count-=1
        elif one_count:
            res.append(1)
            one_count-=1
        else:
            res.append(2)
            two_count-=1

    return res

'''
Optimal Approach
---------------------
LOGIC - Dutch National Flag Algorithm - Take two pointers, send the zeros to the left of first, ones 
to middle, and the twos to the right of second pointer.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
'''

def sort_zeros_ones_twos_optimal( array : List[int] ):
    def swap(array, i, j):
        temp = array[i]
        array[i] = array[j]
        array[j] = temp

    n = len(array)
    low = 0
    high = n-1
    current = 1
    while current < high :
        if array[current] == 0:
            swap(array, current, low)
            low += 1
            current += 1
        elif array[current] == 1:
            current += 1
        else :
            swap(array, current, high)
            high -=1 
        
    return array

#check 
arr = [1, 0, 2, 0, 1, 2, 1, 0]
sorted = sort_zeros_ones_twos_better(arr)
print(sorted)