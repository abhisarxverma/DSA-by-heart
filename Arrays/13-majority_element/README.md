# Problem: Given an array, find the majority element, the number in the array that appears more than half the size of the array.
### Example input : [1, 2, 3, 2, 2, 5, 2]
### Example output : 2

## ✅ Brute Force approach

- LOGIC - Loop the array, and for every element, loop again to calculate it's count, if it is greater than
half the size of the array, return it else return -1;

- TIME COMPLEXITY - O(N^2)
- SPACE COMPLEXITY - O(1)

## ✅ Better approach

- LOGIC - Using a hashmap, to store the count while iterating, and to optimize a little, just after increasing count
of a number, we have to check if the target is met, else pass.

- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(N) hashmap

## ✅ Optimal approach ***( To get the answer pair indexes the better approach is the optimal )***

- LOGIC - Boore-Moyre's voting algorithm, the concept is if a number has count greater than half the size
of array, then while iterating and increasing the count if we find the same number and descreasing the
count if we find other than that, then at last the majority number should be remaining, cause it is one extra than
half the size so no other can cancel out it.

- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(1)