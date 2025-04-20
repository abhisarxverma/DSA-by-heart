# PROBLEM - Given an array of integers, rearrange the array so that one positive, then one negative, one positive and then one negative comes, and also the sequence of the numbers in the original array is maintained.

### Example input : [-3, 2, 5, 0, -1, -10]
### Example output : [2, -3, 5, -1, 0, -10]

## ✅ Brute Force approach

- LOGIC - Take a two pointers for both positives and negatives, and increment both by two while placeing the
numbers in a new array, the pointers will act as index in which the next number should be placed

- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(N)

## ✅ Better approach

- LOGIC - Take two separate vectors for positives and negatives, put the numbers, and the merge them sequentially

- TIME COMPLEXITY - O(2N)
- SPACE COMPLEXITY - O(N)