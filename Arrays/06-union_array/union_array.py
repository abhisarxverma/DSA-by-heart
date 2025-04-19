from typing import List

'''
Brute Force Approach
---------------------
LOGIC - Take a set, and a result vector, loop through all the number in the both arrays, if the number not in set then only add
it to the set and the vector else do nothing, then at last return the sorted vector

TIME COMPLEXITY - O( (N+M) x Log(N+M) ) for sorting
SPACE COMPLEXITY - O( 2(N+M) ) set and list
'''

def union_array_brute( arr1: List[int], arr2 : List[int] ) -> List[int] :
    n = len(arr1)
    m = len(arr2)
    if n+m == 0: return arr1
    elif not n: return arr2
    elif not m: return arr1

    res_set = set()
    res_vec = []
    for i in range(n+m):
        if i < n :
            if arr1[i] not in res_set:
                res_vec.append(arr1[i])
                res_set.add(arr1[i])
        else :
            if arr2[i-n] not in res_set:
                res_vec.append(arr2[i-n])
                res_set.add(arr2[i-n])

    return sorted(res_vec)

'''
Optimal Approach
---------------------
LOGIC - Using the merge sort concept of merging two sorted arrays
TIME COMPLEXITY - O(N+M Log N+M) 
SPACE COMPLEXITY - O(N+M)
'''

def union_array_optimal( arr1 : List[int], arr2 : List[int] ) -> List[int]:
    n = len(arr1)
    m = len(arr2)
    if not n+m: return arr1

    i, j = 0, 0
    res = []
    while i < n and j < m :
        if arr1[i] < arr2[j]:
            res.append(arr1[i])
            i+=1
        elif arr2[j] < arr1[i]:
            res.append(arr2[j])
            j+=1
        else:
            res.append(arr1[i])
            i+=1
            j+=1
    
    while i < n :
        res.append(arr1[i])
        i+=1

    while j < m:
        res.append(arr2[j])
        j+=1

    return res


arr1 = [1, 5, 7, 9]
arr2 = [0, 3, 6, 9]
print(union_array_brute(arr1, arr2))

    