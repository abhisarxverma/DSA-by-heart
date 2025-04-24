from typing import List

'''
 PROBLEM - Given an two sorted arrays, sort them without using any extra space inplace and return them.
 EXAMPLE INPUT - {2, 9, 10} {5, 8, 15, 19}
 EXAMPLE OUTPUT - {2, 5, 8} {9, 10, 15, 19}
'''

'''
Brute Approach
---------------------
LOGIC - Use the Merge sort merging concept, and at last put the sorted array's elements back into the original two arrays.

TIME COMPLEXITY - O(N+M) merging
SPACE COMPLEXITY - O(N+M) merged sorted array
'''

def merge_without_extraspace_brute( array1 : List[int], array2 : List[int] ):
    n = len(array1)
    m = len(array2)
    i = 0
    j = 0
    merged = []
    while i < n and j < m:
        if ( array1[i] < array2[j] ):
            merged.append(array1[i])
            i+=1
        else:
            merged.append(array2[j])
            j+=1

    while i < n:
        merged.append(array1[i])
        i+=1
    while j < m:
        merged.append(array2[j])
        j+=1

    for i in range(n+m):
        if i < n: array1[i] = merged[i]
        else: array2[i-n] = merged[i]

'''
Better Approach
---------------------
LOGIC - 

Expand array1 to fit both arrays by adding zero placeholders.
Use three pointers (i, j, k):
i → Tracks last element in original array1
j → Tracks last element in array2
k → Tracks position in expanded array1
Merge in reverse order:
Compare elements at i and j, placing the larger one at k.
Reduce i or j accordingly.
Copy remaining elements from array2 if any are left.

TIME COMPLEXITY - O(N+M) 
SPACE COMPLEXITY - O(M)
'''

def merge_without_extraspace_better(array1: List[int], array2: List[int]):
    n = len(array1)
    m = len(array2)
    i = n - 1
    j = m - 1
    k = n + m - 1

    # Make space in array1 to hold elements of array2
    array1 += [0] * m

    while i >= 0 and j >= 0:
        if array1[i] >= array2[j]:
            array1[k] = array1[i]
            i -= 1
        else:
            array1[k] = array2[j]
            j -= 1
        k -= 1

    # Copy remaining elements of array2 to array1 if any
    while j >= 0:
        array1[k] = array2[j]
        j -= 1
        k -= 1

    array2[:] = array1[n:]
    array1[:] = array1[:n]

'''
Optimal Approach
---------------------
LOGIC -
Start with a gap size (initially (n + m + 1) // 2), which helps in comparing elements far apart.
Compare and swap:
If both elements are in the first array (array1), swap if needed.
If one element is in array1 and the other in array2, swap if out of order.
If both are in array2, swap if needed.
Reduce the gap gradually and repeat until the entire array is merged properly.

TIME COMPLEXITY - O((n+m) log(n+m))
SPACE COMPLEXITY - O(1)
'''

def merge_without_extraspace_optimal( array1 : List[int], array2 : List[int] ):
    n = len(array1)
    m = len(array2)
    gap = (n + m + 1)//2
    while gap > 0:
        i = 0
        j = gap
        while j < n+m:
            # Both are in the left array
            if j < n and array1[i] > array2[j]:
                array1[i], array2[j] = array2[j], array1[i]
            # One is in the left and one is in the right array
            if i < n and j <= n and array1[i] > array2[j-n]:
                array1[i], array2[j-n] = array2[j-n], array1[i]
            # Both are in the right array
            if i >= n and j >= n and array1[i-n] > array2[j-n]:
                array1[i-n], array2[j-n] = array2[j-n], array1[i-n]
            
            i+=1
            j+=1
        
        gap = 0 if gap == 1 else (gap+1)//2


vec1 = [2, 9, 10]
vec2 = [5, 8, 15, 19]
merge_without_extraspace_better(vec1, vec2)
print(vec1)
print(vec2)
