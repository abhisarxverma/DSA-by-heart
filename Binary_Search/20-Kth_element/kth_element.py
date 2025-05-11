from typing import List

'''
PROBLEM - Given two sorted arrays and an integer "k", find and return the element from the merged sorted array, that is at the kth index.

ARRAY1 = {1,2, 3}
ARRAY2 = {4, 5, 6, 7};
k = 5

OUTPUT = 5
'''

'''
Brute Force Approach
---------------------
LOGIC - Return the kth index element, after merging the two sorted arrays.
Do the merging with the traditional merging process of the mergesort.
After merging return the kth index number from the merged array.

TIME COMPLEXITY - O(N+M) 
SPACE COMPLEXITY - O(N) 
'''

def kth_element_brute( array1: List[int], array2: List[int], k: int ):
    n = len(array1)
    m = len(array2)

    if k >= n+m: return -1

    i = 0, j = 0
    merged = []

    while i < n and j < m:
        if array1[i] < array2[j]:
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

    return merged[k] 


'''
Better Approach
---------------------
LOGIC - While merging, return the kth element
Perform the merging procedure of the mergesort,
And instead of having a whole merged array, simply count the number of merging done till k
And once the merging reach the "k", then return that number.

TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(1) 
'''

def kth_element_better( array1: List[int], array2: List[int], k: int ):
    n = len(array1)
    m = len(array2)
    i = 0
    j = 0
    count = 0

    while i < m and j < m:
        if array1[i] < array2[j]:
            count+=1
            if count == k: return array1[count]
            i+=1
        else :
            count+=1
            if count == k: return array2[count]
            j+=1

    while i < n:
        count+=1
        if count == k: return array1[count]
        i+=1
    
    while j < m:
        count+=1
        if count == k: return array2[count]
        j+=1

    return -1

'''
Optimal Approach
---------------------
LOGIC - Binary search
Use binary search on the smaller array to optimize operations.
Partition both arrays such that the left half contains exactly k elements, ensuring correct positioning of the Kth element.
Maintain four boundary values:
l1 → Largest element in the left partition of array1
l2 → Largest element in the left partition of array2
r1 → Smallest element in the right partition of array1
r2 → Smallest element in the right partition of array2
Check if l1 ≤ r2 and l2 ≤ r1, ensuring a valid partition.
If valid, return the maximum of l1 and l2, as it represents the Kth smallest element.
If l1 > r2, move left in binary search.
Else, move right in binary search.

TIME COMPLEXITY - O(Log min(N,M)) 
SPACE COMPLEXITY - O(1) 
'''

def kth_element_optimal( array1: List[int], array2: List[int], k: int ):
    n = len(array1)
    m = len(array2)
    
    # Ensure a is the smaller array
    if n > m:  return kth_element_optimal(array2, array1, k)

    low = max(0, k - m)
    high = min(k, n)
    left = k

    while low <= high:
        mid1 = (low + high) / 2
        mid2 = left - mid1

        l1 =  array1[mid1 - 1] if mid1 > 0 else float("inf")
        l2 =  array2[mid2 - 1] if mid2 > 0 else float("inf")
        r1 =  array1[mid1] if mid1 < n else float("-inf")
        r2 =  array2[mid2] if mid2 < m else float("-inf")

        if l1 <= r2 and l2 <= r1:
            return max(l1, l2)
        elif l1 > r2:
            high = mid1 - 1
        else:
            low = mid1 + 1

    return -1; 


array1 = [1, 2, 3]
array2 = [4, 5, 6, 7]
k = 4;
print(f"{k}th element of merged {array1} and {array2} is : {kth_element_better(array1, array2, k)}")