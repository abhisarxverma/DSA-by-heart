# PROBLEM - Given an array, find the peak element and return the index of that element.
## For the extremes you can assume that the number before the left extreme is -infinite and the number after the right extreme is -infinite
### Peak element - The element in the array which is greater than the left number and greater than the right number.

## ✅ Brute Force Approach
- **LOGIC** - **Linear search**- Go over the array one by one and check for the conditions and return the index if the conditions are met.
- **TIME COMPLEXITY** - ***O(N)*** 
- **SPACE COMPLEXITY** - ***O(1)***

## ✅ Optimal Approach

- **LOGIC** -
    - A peak element is greater than its neighbors.
    - The left and right sides of the peak are **sorted**.

    ### Binary Search Approach:
    1. **Find mid** of the array.
    2. **Check if mid is a peak**:
    - `arr[mid] > arr[mid-1]` and `arr[mid] > arr[mid+1]`
    3. **Decide the search direction**:
    - If `arr[mid] < arr[mid+1]`, the peak is **on the right**, move right.
    - If `arr[mid] < arr[mid-1]`, the peak is **on the left**, move left.

    ### Why Binary Search?
    - Instead of checking every element, **binary search halves** the search space.
    - **Time Complexity:** O(log N) (efficient compared to O(N)).

- **TIME COMPLEXITY** - ***O(Log N)***
- **SPACE COMPLEXITY** - ***O(1)***