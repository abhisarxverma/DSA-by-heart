# PROBLEM - Given the array, which was sorted but was rotated some number of times, find the given target number and return the index. 

## ✅ Brute
- LOGIC - Linear search- Go over the array one by one and if you find the number return the index.

- TIME COMPLEXITY - ***O(N)*** 
- SPACE COMPLEXITY - ***O(1)***

## ***SUB PROBLEM - If all the elements are unique.***

## ✅ Optimal Approach

- LOGIC - ***Binary Search***
    - In a rotated sorted array, at least one half is always sorted.
    - Check if the left or right part is sorted by comparing the middle element with the leftmost element. 
    - If the target is within the sorted half, search there. Otherwise, move to the unsorted side where the rotation happened. 
    - Repeat the process until you find the number.

- TIME COMPLEXITY - ***O(Log N)***
- SPACE COMPLEXITY - ***O(1)***

## ***SUB PROBLEM - If the array has duplicates***


## ✅ Optimal Approach

- LOGIC - ***Binary Search*** 
    - In a rotated sorted array, one half is always sorted. 
    - To find the first occurrence of the target, store the match and continue searching left for earlier instances.
    - When checking the middle element, identify whether the left or right part is sorted by comparing mid with low.
    - If left is sorted, check if the target falls in that range; otherwise, move to the right (unsorted) side.
    - If right is sorted, do the same—search within if the target fits, otherwise move left.
    - Additionally, if arr[low] == arr[mid] == arr[high], the search could become infinite (due to duplicates). 
    - In this case, increment low and decrement high to escape the loop safely.

- TIME COMPLEXITY - ***O(Log N)***
- SPACE COMPLEXITY - ***O(1)***