# PROBLEM - Rotate the given square matrix in a clockwise direction

###    EXAMPLE INPUT MATRIX 
###         1 2 3 4          
###         5 6 7 8           
###         9 10 11 12       
###         13 14 15 16      

###    EXAMPLE OUTPUT MATRIX
###        13 9 5 1 
###        14 10 6 2
###        15 11 7 3 
###        16 12 8 4

## ✅ Brute Approach

- LOGIC - Loop over the rows, then loop over the columns in reverse order, take a new result vector, place the numbers at their new indexes according to the relation between the indexes - 

- matrix[row][col] -> new_matrix[col][row]

- TIME COMPLEXITY - O(n^2)
- SPACE COMPLEXITY - O(n^2)

## ✅ Optimal Approach

- LOGIC - Transpose the matrix , and then reverse every row of the matrix. Done.

- TIME COMPLEXITY - O(n^2) nearly
- Transpose - O(n/2 * n/2) nearly
- Reverse - O(n * n/2);

- SPACE COMPLEXITY - O(1)