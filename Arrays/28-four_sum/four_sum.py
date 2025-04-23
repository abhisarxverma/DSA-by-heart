from typing import List

'''
 PROBLEM - Given an array of integers, find  and return all the groups of 4 integers that give the desired sum k.
 
 EXAMPLE INPUT - 1, 3, 0, 5, 8, 2, -5, 20 / sum = 10
 EXAMPLE OUTPUT - [-5, 2, 5, 8], [0, 2, 3, 5]
'''

'''
Brute Approach
---------------------
LOGIC - Code a nested 4 loop and in the last loop check the sum if equal to k, if yes,  sort and add that to the set
to store the unique triplets and at last return the vector created from that set.

TIME COMPLEXITY - O(N^4+ LogM) = O(N^4)
SPACE COMPLEXITY - O(N^4) Worst case : Set will store every group of 4 that can be created from the array
'''

def four_sum_brute( array : List[int], target : int ) :
    n = len(array)
    unique_groups = set()
    for i in range(n):
        for j in range(i+1, n):
            for k in range(j+1, n):
                for l in range(k+1, n):
                    sum = array[i] + array[j] + array[k] + array[l]
                    if sum == target:
                        group = sorted([array[i], array[j], array[k], array[l]])
                        unique_groups.add(tuple(group))

    return list(unique_groups)

'''
Better Approach
---------------------
LOGIC - Code a nested 3 nested loop and in that 2nd loop create a hashset to store the numbers that 3rd loop will visit and
while in the 3rd loop if you find the number on adding to the current sum that will become the target in the hashset that means
that we have found a group that gives the target sum, sort and add that to the final result set to store unique groups only.

TIME COMPLEXITY - O(N^3+ LogM) = O(N^3)
SPACE COMPLEXITY - O(N^3) Worst case : Set will store every group of 4 that can be created from the array
'''

def four_sum_better( array : List[int], target : int ):
    n = len(array)
    unique_groups = set()
    for i in range(n):
        for j in range(i+1, n):
            visited = set()
            for k in range(j+1, n):
                sum = array[i] + array[j] + array[k]
                remaining = target - sum
                if remaining in visited:
                    group = tuple(sorted((array[i], array[j], array[k], remaining)))
                    unique_groups.add(group)
                visited.add(array[k])

    return list(unique_groups)

'''
Optimal Approach
---------------------
LOGIC - 4 pointer approach, sort the array, run 2 loops and in the second loop, take 2 pointers, one at start and one
at end, and move them according to the current sum, if less than target mover the end pointer back else mover the start
pointer forward and eventually all the groups with the target sum will fall in our bag.

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(N^4) Worst case : Set will store every group of 4 that can be created from the array
                    but this also to return the result groups else O(1) to get groups.
'''

def four_sum_optimal( array : List[int], target : int ):
    n = len(array)
    res = []
    array = sorted(array)
    for i in range(n):
        if i > 0 and array[i-1] == array[i]: continue
        for j in range(i+1, n):
            if array[j] == array[j-1]: continue
            k = j+1
            l = n-1
            while k < l:
                sum = array[i] + array[j] + array[k] + array[l]
                if sum < target: k+=1
                elif sum > target: l-=1
                else :
                    group = (array[i], array[j], array[k], array[l])
                    res.append(group)
                    k+=1
                    l-=1
                    while k < l and array[k] == array[k-1]: k+=1
                    while k < l and array[l] == array[l+1]: l-=1

    return res


array = [1, 3, 0, 5, 8, 2, -5, 20]
ans = four_sum_optimal(array, 10)
for group in ans:
    for num in group:
        print(num, end=" ")
    print()
