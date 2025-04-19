# Problem: Given an array consisting only zeros, ones and twos, sort it.
### Example input : [1, 0, 2, 0, 1]
### Example output : [0, 0, 1, 1, 2]

## ✅ Brute Force approach

- LOGIC - Use any sorting method like bubble sort O(n^2), merge sort (n log n), quick sort (n^2), selection sort(n^2), insertion sort(n^2)
I have used the selection sort.

- TIME COMPLEXITY - O(N^2)
- SPACE COMPLEXITY - O(1)

## ✅ Better approach

- LOGIC - Count the number of zeros, ones and twos, then loop for the array size times, and place first the zeros, then ones and then twos

- TIME COMPLEXITY - O(2N) = O(N)
- SPACE COMPLEXITY - O(1)

## ✅ Optimal approach ***( To get the answer pair indexes the better approach is the optimal )***

- LOGIC - Dutch National Flag Algorithm - Take two pointers, send the zeros to the left of first, ones 
to middle, and the twos to the right of second pointer.

- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(1)