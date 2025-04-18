# Problem: Remove the duplicate elements form the array

## ✅ Brute
- Logic - use a set to store the seen numbers and if the number is not seen then add that into vector
- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(2N) - set and result vector

## ✅ Better
- Logic - create a new vector and iterate through the original vector, add into the result vector if the number is not equl to the last element of the vector
- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(N)


## ✅ Optimal
- Logic: 
    1. Take a pointer 'back' and initialize it to zero, loop from 1st index to end 
    2. If the number at that index is not equal to number at back index. Then make the number next to the back index that number and increment the back.
    3. At Last resize the array to back + 1 cause the till back index all the number will be unique.

- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(1)