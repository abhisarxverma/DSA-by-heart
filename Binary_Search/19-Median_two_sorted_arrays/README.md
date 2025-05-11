# PROBLEM - Given two sorted array of maybe different sizes, Find the median of the merged sorted array.

### ARRAY1 = {1,2, 3}
### ARRAY2 = {4, 5, 6, 7};
### MEDIAN = 4

## ✅ Brute Force Approach

- **LOGIC** - *Find Median after Merging the two sorted arrrays.*
    - Merge the given two sorted arrays, through the traditional merging process of the mergesort.
    - At last if the sum of length of the new merged array is odd then return the direct mid of the merged
    - and if the sum of length of the new merged array is even then return the sum of the two mid divided by 2.

- **TIME COMPLEXITY** - ***O(N+M)***
- **SPACE COMPLEXITY** - ***O(N)***

## ✅ Better Approach

- **LOGIC** - *Find Median while Merging the two sorted arrrays.*
    - We perform the traditional merge process from Merge Sort but without storing the merged array.
    - Instead, we track only two key values—element1 and element2—which represent the median.
    - A counter keeps track of merged elements, and when it reaches either median index, we store the respective value.
    - Finally, if the total length is even, we return the average of both elements; otherwise, we return element2 as the median.

- **TIME COMPLEXITY** - ***O(N+M)***
- **SPACE COMPLEXITY** - ***O(1)***

## ✅ Optimal Approach

- **LOGIC** - *Binary Search*
    - Use binary search on the smaller array to optimize operations.
    - Partition both arrays to create left and right halves, ensuring the left half contains the median.
    - Maintain four boundary values:
    - `l1` → Leftmost of array1 partition
    - `l2` → Leftmost of array2 partition
    - `r1` → Rightmost of array1 partition
    - `r2` → Rightmost of array2 partition
    - Check if `l1 ≤ r2` and `l2 ≤ r1`, ensuring valid partitioning.
    - If valid, return the median:
    - Odd total length → Largest left partition value `(max(l1, l2))`.
    - Even total length → Average of `max(l1, l2)` and `min(r1, r2)`.
    - If `l1 > r2`, move left in binary search.
    - Else, move right in binary search.

- **TIME COMPLEXITY** - ***O(Log(Min(array1, array2)))*** 
- **SPACE COMPLEXITY** - ***O(1)***