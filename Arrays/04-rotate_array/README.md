# Problem: Rotate the array by given number of times

## ✅ Brute
- LOGIC - Take a temporary array, put all the numbers before the rotation point that is before the index times into temp then shift the numbers after the index times including to either edge based on the direction of rotation and then put the number from the temporary array to the left or right based on the direction of rotation.

- TIME COMPLEXITY - O(2N)
- SPACE COMPLEXITY - O(times) temp array

## ✅ Better
- LOGIC - Loop for times, and every time while shifting every number to left send the first        element of the array to the back in case of left rotation and send the last number to front in case of right rotation.

- TIME COMPLEXITY - O(N x K) *Removes space but on worst case runs for very long.*
- SPACE COMPLEXITY - O(1)


## ✅ Optimal
Better Approach
---------------------
- LOGIC - reverse the part before the point of rotation (index - times) , then reverse the rest part, then revese the whole array

- TIME COMPLEXITY - O(2N) = O(N)
- SPACE COMPLEXITY - O(1)