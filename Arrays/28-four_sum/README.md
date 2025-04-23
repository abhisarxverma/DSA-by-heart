# PROBLEM - Given an array of integers, find  and return all the groups of 4 integers that give the desired sum k.
 
### EXAMPLE INPUT - 1, 3, 0, 5, 8, 2, -5, 20 / sum = 10
### EXAMPLE OUTPUT - [-5, 2, 5, 8], [0, 2, 3, 5]


## ✅ Brute Approach

- LOGIC - Code a nested 4 loop and in the last loop check the sum if equal to k, sort and add that to the set
to store the unique triplets and at last return the vector created from that set.

- **TIME COMPLEXITY** - O(N^4+ LogM) = O(N^4) *Due to four nested loops*
- **SPACE COMPLEXITY**- O(N^4) *Worst case : Set will store every group of 4 that can be created from the array*

## ✅ Better Approach

- LOGIC - 
    1. Run **three nested loops** to fix three numbers.
    2. In the **second loop**, use a HashSet to store numbers visited in the third loop.
    3. In the **third loop**, check if `target - current sum` exists in the HashSet.
    4. If found, sort and store the unique group in the result set.

- **TIME COMPLEXITY** - O(N^3+ LogM) = O(N^3)
- **SPACE COMPLEXITY** - O(N^3) *Worst case : Set will store every group of 4 that can be created from the array*

## ✅ Optimal Approach

- LOGIC - 
    1. **Sort the Array**  
   - Sorting helps in applying the two-pointer technique efficiently.

    2. **Use Two Nested Loops to Fix Two Elements**  
    - First loop (`i`) selects the first number.  
    - Second loop (`j`) selects the second number (`j > i`).

    3. **Use Two Additional Pointers to Find Remaining Numbers**  
    - `left` pointer starts at `j + 1`.  
    - `right` pointer starts at the end of the array.  

    4. **Adjust Pointers Based on the Current Sum**  
    - **If sum equals the target:** Store the quadruplet and move both pointers past duplicates.  
    - **If sum is less than target:** Increase the sum by moving the **left pointer forward**.  
    - **If sum is greater than target:** Decrease the sum by moving the **right pointer backward**.

    5. **Repeat Until All Valid Groups Are Found**  
    - By following this approach, all sets of four numbers that match the target sum will be efficiently captured.

### **Why is This Optimal?**
- **TIME COMPLEXITY** - O(N²) *Complexity ( Improved from O(N³) brute force )*.  
- **SPACE COMPLEXITY** - O(N^4) *Worst case : Set will store every group of 4 that can be created from the array but this space only to return the result groups else O(1) to get groups.*
