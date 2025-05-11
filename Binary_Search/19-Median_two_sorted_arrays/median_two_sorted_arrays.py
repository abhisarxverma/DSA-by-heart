from typing import List

'''
PROBLEM - Given two sorted array of maybe different sizes, Find the median of the merged sorted array.

ARRAY1 = {1,2, 3}
ARRAY2 = {4, 5, 6, 7};
MEDIAN = 4
'''

'''
Brute Force Approach
---------------------
LOGIC - Find Median after Merging the two sorted arrrays.
Merge the given two sorted arrays, through the traditional merging process of the mergesort.
At last if the sum of length of the new merged array is odd then return the direct mid of the merged
and if the sum of length of the new merged array is even then return the sum of the two mid divided by 2.

TIME COMPLEXITY - O(N+M) 
SPACE COMPLEXITY - O(N)
'''

def median_brute( array1: List[int], array2: List[int] ):
    i = 0
    j = 0
    n = len(array1)
    m = len(array2)
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

    s = n+m
    if (s % 2 != 0) : return merged[s // 2]
    else : return (merged[s // 2 - 1] + merged[s // 2]) // 2.0

'''
Better Approach
---------------------
LOGIC - Find Median while Merging the two sorted arrrays.
We perform the traditional merge process from Merge Sort but without storing the merged array.
Instead, we track only two key values—element1 and element2—which represent the median.
A counter keeps track of merged elements, and when it reaches either median index, we store the respective value.
Finally, if the total length is even, we return the average of both elements; otherwise, we return element2 as the median.

TIME COMPLEXITY - O(N+M) 
SPACE COMPLEXITY - O(1)
'''

def median_better( array1: List[int], array2: List[int] ):
    i = 0
    j = 0
    n = array1.size()
    m = array2.size()
    index2 = (n+m)/2
    index1 = index2 - 1
    count = 0
    element1 = -1
    element2 = -1

    while  i < n and j < m :
        if array1[i] < array2[j] :
            if  count == index1 : element1 = array1[i]
            if  count == index2 : element2 = array1[i]
            count+=1
            i+=1
        else :
            if count == index1 : element1 = array2[j]
            if count == index2 : element2 = array2[j]
            count+=1
            j+=1

    while i < n:
        if count == index1 : element1 = array1[i]
        if count == index2 : element2 = array1[i]
        count+=1
        i+=1
    
    while j < m:
        if count == index1 : element1 = array2[j]
        if count == index2 : element2 = array2[j]
        count+=1
        j+=1

    if (n+m)%2 == 0: return (element1+element2)/2.0
    else: return element2


'''
Optimal Approach
---------------------
LOGIC - Binary Search
Use binary search on the smaller array to optimize operations.
Partition both arrays to create left and right halves, ensuring the left half contains the median.
Maintain four boundary values:
l1 → Leftmost of array1 partition
l2 → Leftmost of array2 partition
r1 → Rightmost of array1 partition
r2 → Rightmost of array2 partition
Check if l1 ≤ r2 and l2 ≤ r1, ensuring valid partitioning.
If valid, return the median:
Odd total length → Largest left partition value (max(l1, l2)).
Even total length → Average of max(l1, l2) and min(r1, r2).
If l1 > r2, move left in binary search.
Else, move right in binary search.

TIME COMPLEXITY - O(Log(Min(array1, array2))) 
SPACE COMPLEXITY - O(1)
'''

def median_optimal( array1: List[int], array2: List[int] ):
    n = array1.size()
    m = array2.size()
    if ( n > m ) : return median_optimal(array2, array1)
    low = 0, high = n
    left = (n + m + 1)/2
    s = n + m
    while low <= high:
        mid1 = (low+high)/2
        mid2 = left - mid1
        l1 = INT_MIN, l2 = INT_MIN
        r1 = INT_MAX, r2 = INT_MAX
        if mid1 < n : r1 = array1[mid1]
        if mid2 < m : r2 = array2[mid2]
        if mid1 - 1 >= 0 : l1 = array1[mid1-1]
        if mid2 - 1 >= 0 : l2 = array2[mid2-1]

        if l1 <= r2 and l2 <= r1:
            if(s % 2 == 1) : return max(l1, l2);
            return  (max(l1, l2) + min(r1, r2)) // 2
        
        elif l1 > r2 : high = mid1-1
        else : low = mid1+1
    
    return 0


array1 = [1,2, 3]
array2 = {4, 5, 6, 7}
median = median_optimal(array1, array2)
print(f"Median of two sorted arrays : {median}")