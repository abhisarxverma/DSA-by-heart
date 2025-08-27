## PROBLEM - Given a matrix, find the shortest path sum from the start to the end of the matrix i.e 0:0 to rows-1:cols-1 of the matrix.

## I solved this all myself without single help, for which i am proud of

## RECURSION IS THE WAY TO SOLVE THIS

### Why not traditional loops?
A Traditional loop can only check one level of possibility of answers but in this type of questions we need to check every possibility for every move and backtrack also.

### LOGIC - 

1. **Base Case**  
   - If the current row and column reach the destination, stop recursion.  
   - Return the current sum and the path taken.

2. **Find Possible Moves**  
   - From the current cell, check all four directions (up, down, left, right).  
   - A move is valid if:  
     - It’s inside the matrix.  
     - It’s not the starting point again.  
     - It’s not already part of the current path (to avoid loops).

3. **Track Best Result**  
   - Keep two variables:  
     - `shortest_sum` → the smallest sum found so far.  
     - `shortest_path` → the path that produced this sum.

4. **Explore Each Move**  
   - For every valid move:  
     - Add the move to the current path.  
     - Add the block’s value to the path sum.  
     - Recursively call the function with the new position.  
     - After recursion, remove the move and value (backtracking).  
     - Compare the result with `shortest_sum`.  
       - If the new sum is smaller, update `shortest_sum` and `shortest_path`.

5. **Return the Best Answer**  
   - After checking all possible moves, return `(shortest_sum, shortest_path)`.
   
### TIME COMPLEXITY - O(N x M)
### SPACE COMPLEXITY - O(N X M) Recursion call stack