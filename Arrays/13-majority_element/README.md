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

## ✅ Optimal approach *Boyre-Moore's Voting algorithm*

- LOGIC -
- 
1. **Majority Element Condition**  
   - If an element appears **more than half the size of the array**, it must remain by the end of the process.

2. **Tracking Candidate Element**  
   - Initialize a **candidate** variable and a **count** tracker.
   - Traverse the array:
     - **Increase count** if the current element matches the candidate.
     - **Decrease count** if the current element differs from the candidate.
     - If count reaches **zero**, update the candidate to the current element and reset count.

3. **Final Result**  
   - By the end of the iteration, the majority element remains because its occurrences exceed half of the array size.
   - Optional verification: A second pass can confirm if the candidate truly appears more than ⌊N/2⌋ times.

- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(1)
