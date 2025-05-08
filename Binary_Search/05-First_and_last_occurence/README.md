# PROBLEM - Given the sorted array and the number, return the first and the last occurence of the number in the array using binary search 

## ✅ Brute
- LOGIC - First find the first occurence and then the find the last occurence by changing the traditional lower and upper bound, and then return the answer together.

    ***First occurence loop conditions***
    - If the mid is equal to the number we are finding, then save the number and go to left
    - If the mid is lower than the number we are finding, then go to the right
    - If the mid is greater than the number we are finding, just go to the left

    ***Second occurence loop conditions***
    - If the mid is equal to the number we are finding, then save the number and go to the right.
    - If the mid is lower than the number we are finding, then go to the right
    - If the mid is greater than the number we are finding, then go to the left

- TIME COMPLEXITY - ***O(2 LOGN)*** 
- SPACE COMPLEXITY - ***O(1)***

## ✅ Optimal Approach
- LOGIC -
    - The first occurrence of a number in a sorted array is found using lower bound, which returns:
    - The index of the number if it exists.
    If the number isn't present, it returns the index of the next greater number.
    - The last occurrence is based on upper bound, which:
    - Always returns the index of the next greater number in the array.
    So, if lower bound confirms the number is present, the last occurrence is simply upper bound - 1. 
    - If lower bound doesn’t find the exact number, return -1 for both occurrences.

- TIME COMPLEXITY - ***O(2 LOGN)*** *Same complexity but simple lower and upper bound usage*
- SPACE COMPLEXITY - ***O(1)***