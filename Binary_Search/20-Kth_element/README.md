# PROBLEM - Given two sorted arrays and an integer "k", find and return the element from the merged sorted array, that is at the kth index.

### ARRAY1 = {1,2, 3}
### ARRAY2 = {4, 5, 6, 7};
### k = 5

### OUTPUT = 5

## ✅ Brute Force Approach

- **LOGIC** - *Return the kth index element, after merging the two sorted arrays.*
    - Do the merging with the traditional merging process of the mergesort.
    - After merging return the kth index number from the merged array.

- **TIME COMPLEXITY** - ***O(N+M)***
- **SPACE COMPLEXITY** - ***O(N)***

## ✅ Better Approach

- **LOGIC** - *While merging, return the kth element*
    - Perform the merging procedure of the mergesort,
    - And instead of having a whole merged array, simply count the number of merging done till k
    - And once the merging reach the "k", then return that number.

- **TIME COMPLEXITY** - ***O(N)***
- **SPACE COMPLEXITY** - ***O(1)*** 

## ✅ Optimal Approach

- **LOGIC** - *Binary search*
    - Use binary search on the smaller array to optimize operations.
    - Partition both arrays such that the left half contains exactly k elements, ensuring correct positioning of the Kth element.
    - Maintain four boundary values:
    - l1 → Largest element in the left partition of array1
    - l2 → Largest element in the left partition of array2
    - r1 → Smallest element in the right partition of array1
    - r2 → Smallest element in the right partition of array2
    - Check if l1 ≤ r2 and l2 ≤ r1, ensuring a valid partition.
    - If valid, return the maximum of l1 and l2, as it represents the Kth smallest element.
    - If l1 > r2, move left in binary search.
    - Else, move right in binary search.

- **TIME COMPLEXITY** - ***O(Log min(N,M))***
- **SPACE COMPLEXITY** - ***O(1)***