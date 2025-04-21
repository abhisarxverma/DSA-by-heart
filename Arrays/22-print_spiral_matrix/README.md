# PROBLEM - Given a matrix print it's elements in spiral order

###    EXAMPLE INPUT MATRIX 
###         1 2 3 4          
###         5 6 7 8           
###         9 10 11 12       
###         13 14 15 16      

###    EXAMPLE OUTPUT - 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

## ✅ Optimal Approach

- LOGIC - Take 4 variables to keep track of the rows and columns to print and got printed, and move in 
spiral order while updating the variables.

- TIME COMPLEXITY - O(NxM)
- SPACE COMPLEXITY - O(1)