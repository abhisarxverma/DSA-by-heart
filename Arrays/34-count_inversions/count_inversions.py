from typing import List

'''
 PROBLEM - Count the total number of the pairs that can be formed in which the first element is greater than the second one.

 EXAMPLE INPUT - {8, 6, 1, 7, 5, 2, 3, 8}
 EXAMPLE OUTPUT - 15
'''

'''
Brute Approach
---------------------
LOGIC - Loop over the array and then loop over the right of the array and increase the count if 
you find a pair in which the second element is smaller than the frist one.

TIME COMPLEXITY - O(N^2) two-nested-loops
SPACE COMPLEXITY - O(1)
'''

def count_inversion_brute( array : List[int] ):
    count = 0
    n = len(array)
    for i in range(n):
        for j in range(i+1, n):
            if array[i] > array[j]: count+=1

    return count

'''
Optimal Approach
---------------------
LOGIC - MERGE SORT APPROACH - Using the MERGESORT concept of merging the sorted arrays. while merging we will get the count by compairing the elements with the trick

TIME COMPLEXITY - O(N LogN) Merge sort time complexity
SPACE COMPLEXITY - O(N) for merging
'''

def get_count_with_merging( array : List[int], low, mid, high ):
    i = low
    j = mid+1
    res = 0
    b = []
    while i <= mid and j <= high:
        if array[i] <= array[j]:
            b.append(array[i])
            i+=1
        else :
            b.append(array[j])
            res += mid-i+1
            j+=1

    while i <= mid: 
        b.append(array[i])
        i+=1
    while j <= high: 
        b.append(array[j])
        j+=1
    

    # Copy back merged result into original array
    for k in range(len(b)):
        array[low + k] = b[k]
        
    return res
    

def count_inversions_optimal(array : List[int], low, high):
    if low >= high: return 0  # Base case

    mid = (low+high)//2
    leftCount = count_inversions_optimal(array, low, mid)
    rightCount = count_inversions_optimal(array, mid + 1, high)
    mergeCount = get_count_with_merging(array, low, mid, high)

    return leftCount + rightCount + mergeCount;  # Accumulate total inversion count


vec = [8, 6, 1, 7, 5, 2, 3, 8]
inversions = count_inversions_optimal(vec, 0, len(vec)-1)
print(f"Inversions : {inversions}")