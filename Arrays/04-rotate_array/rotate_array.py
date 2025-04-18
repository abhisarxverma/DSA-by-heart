from typing import List

'''
Brute Force Approach
---------------------
LOGIC - Take a temporary array, put all the numbers to before the rotation point that is before the times of rotation
shif the original array and then put the number from the temporary array to the left or right based on the direction of rotation
TIME COMPLEXITY - O(2N)
SPACE COMPLEXITY - O(times) temp array
'''

def left_rotation_brute( array:List[int], times:int ) -> List[int]:
    n = len(array)
    if n <= 1: return array
    times = times % n
    if times == 0: return array
    temp = []
    for i in range(times): temp.append(array[i])
    for i in range(times, n): array[i-times] = array[i]
    for i in range(times): array[n-times+i] = temp[i]
    return array

def right_rotation_brute( array:List[int], times:int ) -> List[int]:
    n = len(array)
    if n <= 1: return array
    times = times % n
    if times == 0: return array
    temp = []
    for i in range(times): temp.append(array[n-times+i])
    for i in range(n-times-1, -1, -1): array[i+times] = array[i]
    for i in range(times): array[i] = temp[i]
    return array

'''
Better Approach
---------------------
LOGIC - Loop for times, and every time while shifting every number to left send the first element of the array to the back.
TIME COMPLEXITY - O(N x K) Removes space but on worst case runs for very long.
SPACE COMPLEXITY - O(1)
'''

def left_rotation_better( array : List[int], times : int ):
    n = len(array)
    if n <= 1: return array
    times = times % n
    if times == 0: return array
    for i in range(times):
        first = array[0]
        for j in range(n-1): array[j] = array[j+1]
        array[-1] = first
    return array

def right_rotation_better( array : List[int], times : int ):
    n = len(array)
    if n <= 1: return array
    times = times % n
    if times == 0: return array
    for i in range(times):
        last = array[-1]
        for j in range(n-1, 0, -1): array[j] = array[j-1]
        array[0] = last
    return array

'''
Optimal Approach
---------------------
LOGIC - reverse the part before the point of rotation , then reverse the rest part, then revese the whole array
TIME COMPLEXITY - O(2N) = O(N)
SPACE COMPLEXITY - O(1)
'''

def left_rotation_optimal( array : List[int], times : int ):
    n = len(array)
    if n <= 1: return array
    times = times % n
    if times == 0: return array
    array[:times] = array[times-1::-1]
    array[times:] = array[:times-1:-1]
    array = array[::-1]
    return array

def right_rotation_optimal( array: List[int], times : int ):
    n = len(array)
    if n <= 1: return array
    times = times % n
    if times == 0: return array
    array[n-times:] = array[:n-times-1:-1]
    array[:n-times] = array[n-times-1::-1]
    array = array[::-1]
    return array

arr = [1, 2, 3, 4, 5, 6, 7]
print(left_rotation_optimal(arr, 3))
arr = [1, 2, 3, 4, 5, 6, 7]
print(right_rotation_optimal(arr, 2))