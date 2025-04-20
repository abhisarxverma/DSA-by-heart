# PROBLEM - Find the maximum length of a consecutive sequence that can be formed from the elements of the array

### Input : {5, 100, 4, 101, 102, 99, 3}
### Output : 4 [99, 100, 101, 102]

## ✅ Brute Approach

- LOGIC - loop every element, and search and increment the array till you do not find the next consecutive number
update the max_length if you found greater length of consecutive sequence.

- TIME COMPLEXITY - O(N^2) nearly
- SPACE COMPLEXITY - O(1)

## ✅ Better Approach

- LOGIC -
1. **Sort the Array**  
   - Sorting ensures numbers appear in ascending order, simplifying the search for consecutive elements.

2. **Initialize a Tracking Variable**  
   - Use a variable (`last_smaller`) to store the previous number that should precede the next in a consecutive sequence.

3. **Iterate Through the Array**  
   - For each number:
     - Check if `current_number - 1 == last_smaller`
       - If true, the sequence continues → **increment count**
     - If the current number is **a duplicate of the last_smaller**, skip it.
     - If the number is **not equal to last_smaller**, reset the count to **1** and update `last_smaller` to the current number.

4. **Track the Longest Consecutive Sequence**  
   - Continuously update the longest sequence found during iteration.

This method efficiently identifies the longest run of consecutive numbers while handling duplicates correctly.

- TIME COMPLEXITY - O(N log N) 
- SPACE COMPLEXITY - O(1)

## ✅ Optimal Approach

- LOGIC
1. **Store numbers in a set**  
   - Insert all elements into an **unordered set** to allow fast lookups.

2. **Identify potential sequence starters**  
   - Loop through each number in the array.  
   - If a number **does not have a consecutive lesser (num - 1)** in the set, it is the **first number** of a new sequence.

3. **Expand and find the longest sequence**  
   - From the identified sequence starter, incrementally check for **next consecutive numbers** in the set.  
   - Continue increasing the sequence count until no further consecutive numbers exist.

4. **Track the maximum sequence length**  
   - Update the longest consecutive length found during iteration.

This ensures an **O(N) time complexity**, making the approach highly efficient.

- TIME COMPLEXITY - O(N) 
- SPACE COMPLEXITY - O(N) set