from typing import List

'''
 PROBLEM - COUNT THE NUMBER OF THE REVERSE PAIRS WHICH ARE THE PAIRS IN WHICH THE LEFT ELEMENT IS MORE THAN TWICE OF THE RIGHT ELEMENT SIMILAR TO THE COUNT INVERSIONS

 EXAMPLE INPUT - {8, 6, 1, 7, 5, 2, 3, 8}, n = 8
 EXAMPLE OUTPUT - 8
'''

'''
Brute Approach
---------------------
LOGIC - Loop over the array and then loop over the array on the right and increase the count
if you find any pair in which the first element is greater than the double the second element.

TIME COMPLEXITY - O(N^2) two-nested-loops
SPACE COMPLEXITY - O(1)
'''

def count_reversepairs_brute( array : List[int] ):
    n = len(array)
    count = 0
    for i in range(n):
        for j in range(i+1, n):
            if array[i] > 2*array[j]: count+=1
    
    return count


'''
Optimal Approach
---------------------
LOGIC - MERGE SORT APPROACH - 
  1. Before merging, counting elements in the right half where `array[i] > 2 * array[j]` using a two-pointer technique.
  2. Merging the two halves while maintaining order.

TIME COMPLEXITY - O(N^2) two-nested-loops
SPACE COMPLEXITY - O(1)
'''

def merge_with_counting( array:List[int], low, mid, high):

    # **Optimized Reverse Pair Counting Using Two Pointers**
    j = mid + 1
    for i in range(low, mid+1):
        while j <= high and array[i] > 2 * array[j]: 
            j+=1
        count += j - (mid + 1);  
    

    # Standard merge process
    b = []
    i = low
    j = mid + 1

    while i <= mid and j <= high:
        if array[i] <= array[j] :
            b.append(array[i])
            i+=1
        else: 
            b.append(array[j])
            j+=1

    while i <= mid:
        b.append(array[i])
        i+=1
    while j <= high:
        b.append(array[j])
        j+=1

    for k in range(len(k)):
        array[low + k] = b[k];  

    return count

def count_reversepairs_optimal( array, low, high ):
    if low >= high: return 0  # Base case

    mid = (low + high) / 2
    leftCount = count_reversepairs_optimal(array, low, mid)
    rightCount = count_reversepairs_optimal(array, mid + 1, high)
    mergeCount = merge_with_counting(array, low, mid, high)

    return leftCount + rightCount + mergeCount;  # ✅ Accumulate total count



vec = [8, 6, 1, 7, 5, 2, 3, 8]
reversepairs = count_reversepairs_optimal(vec, 0, vec.size()-1)
print(f"Total reversepairs : {reversepairs}")
