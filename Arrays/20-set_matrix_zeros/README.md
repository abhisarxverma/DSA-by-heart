# PROBLEM - Given a matrix of zeros and ones, make all the numbers of the row and column zero, if a zero is present.

###     EXAMPLE INPUT MATRIX      EXAMPLE OUTPUT MATRIX
###        1, 1, 1, 1, 1             0, 0, 1, 0, 0
###        0, 1, 1, 0, 1             0, 0, 0, 0, 0
###        1, 1, 1, 1, 0             0, 0, 1, 0, 0
###        1, 0, 1, 1, 1             0, 0, 0, 0, 0
###        1, 1, 1, 1, 1             0, 0, 1, 0, 0

## ✅ Brute Approach

- LOGIC - 

1. **Iterate Through the Matrix**  
   - Loop over each **row**, then loop over each **column** to check for zero values.

2. **Mark Zero Positions Using `-1` Instead of `0`**  
   - If a **zero is found**, mark all elements in its **row and column** as `-1`.  
   - This prevents premature conversion to `0`, avoiding unnecessary updates in later steps.

3. **Convert Marked `-1` Values to `0`**  
   - After the full traversal, loop through the matrix again and **change all `-1` values to `0`**, ensuring correctness.

### **Why Use `-1` Instead of Direct `0`?**  
- If we set numbers to **zero immediately**, later iterations may incorrectly modify numbers **before checking all conditions**.  
- Using `-1` allows us to safely **differentiate originally existing zeros** from newly marked positions.

- TIME COMPLEXITY - O(NxM x N+M)
- SPACE COMPLEXITY - O(1)

## ✅ Better Approach

- LOGIC - 

1. **Initialize Two Vectors**  
   - Use a **row vector** and a **column vector** to track which rows and columns need to be set to `0`.

2. **Mark Rows and Columns for Zeroing**  
   - Traverse the matrix:  
     - If a cell is `0`, mark its row index in the **row vector** and its column index in the **column vector**.

3. **Update the Matrix**  
   - Loop through the matrix again:  
     - If a row is marked in the **row vector** or a column is marked in the **column vector**, set the entire row or column to `0`.

- TIME COMPLEXITY - O(2 NxM)
- SPACE COMPLEXITY - O(N+M)

## ✅ Optimal Approach

- LOGIC -

1. **Use the first row and first column as storage:**  
   - Instead of using extra space, store information about which rows and columns should be set to zero in the **first row** and **first column** of the matrix.

2. **Mark zero positions:**  
   - Traverse the matrix, and whenever a cell **contains `0`**, mark its row and column in the **first row and first column**.

3. **Update the matrix based on stored values:**  
   - After marking, iterate again and set corresponding rows and columns to **zero** based on the values in the first row and first column.

4. **Handle the first row and first column separately:**  
   - If the **first column of the first row** was marked as zero, set the **entire first row** to zero.  
   - Use a separate variable (`col0`) to track whether the **first column** should be entirely zero. If `col0` is `true`, set the **first column** to zero.

- TIME COMPLEXITY - O(2 NxM) = O(NxM)
- SPACE COMPLEXITY - O(1)