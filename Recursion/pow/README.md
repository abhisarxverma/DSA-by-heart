## PROBLEM - Implement the builtin pow function of the python that takes two integers x and n and returns the number which is the x raised to the power n

### We will implement the solution first in the loop and then in the recursion, this will teach more.

### ✅ BRUTE FORCE APPROACH - *Traditional for loop [ This will cause the Run Time Error]*
---------------------------------------------------------------------------------------------
- **LOGIC** - 
    - Take a `res` integer variable
    - run a for loop for n times and everytime multiply the x to the res
    - return the res

- **TIME COMPLEXITY** - ***O(N)***
- **SPACE COMPLEXITY** - ***O(1)***


### ✅ OPTIMAL APPROACH - *Using simple maths*
---------------------------------------------------------------
- **LOGIC** - 
    - Take a `res` integer variable
    - run a while loop till the n is greater than 1
    - in the loop check if the n is odd or even
    - if the n is even then multiply the `x` in the res two times and divide the power by 2
    - if the n is odd then multiply the `x` in the res one time and reduce the power by 1
    - return the res after loop breaks

- **TIME COMPLEXITY** - ***O(Log N)***
- **SPACE COMPLEXITY** - ***O(1)***


<div style="display: flexbox; text-align: center; font-family: monospace;">
    <h1>THANK YOU!</h1>
</div>