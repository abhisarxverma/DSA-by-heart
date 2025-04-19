from typing import List

'''
Brute Force Approach
---------------------
LOGIC - Loop over the any one vector, the nestedly loop over other vector, and if you find any number same as the outer number 
then add it to the result vector, and it will automatically be in sorted order, so no need to sort.
straight return the result vector.

TIME COMPLEXITY - O((N+M)^2)
SPACE COMPLEXITY - O(N+M) result array to return
'''

def intersection_array_brute( arr1 : List[int], arr2 : List[int] ) -> List[int] :
    n = len(arr1)
    m = len(arr2)
    if not n+m: return arr1

    res = []
    for i in arr1:
        for j in arr2:
            if i == j and i not in res: res.append(i)

    return res

'''
Optimal Approach
---------------------
LOGIC - Using the merge sort concept of merging two sorted arrays
TIME COMPLEXITY - O(N+M) 
SPACE COMPLEXITY - O(N+M)
'''

def intersection_array_optimal( arr1 : List[int], arr2 : List[int] ) -> List[int] :
    n = len(arr1)
    m = len(arr2)
    if not n+m : return arr1

    i, j = 0, 0
    res = []
    while i < n and j < m :
        if arr1[i] < arr2[j]:
            i+=1
        elif arr2[j] < arr1[i]:
            j+=1
        else:
            res.append(arr1[i])
            i+=1
            j+=1

    return res

arr1 = [1, 5, 7, 9]
arr2 = [0, 3, 6, 9]
print(intersection_array_optimal(arr1, arr2))