## PROBLEM - Implement the builtin pow function of the python that takes two integers x and n and returns the number which is the x raised to the power n, n can be any integer in the range of an integer

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
   - Initialize an integer variable `res` to 1
    - While `n` is greater than 0: 
    - If `n` is odd:
        - Multiply `res` by `x` once
        - Decrease `n` by 1
        - > Maths used - `x^n = x * x^n-1`
    - Else (i.e., `n` is even):
        - Square the base `x` (i.e., `x = x * x`)
        - Divide `n` by 2
        - > Maths used - `x^n = (x^2)^n/2`
    - Return `res` as the final result


- **TIME COMPLEXITY** - ***O(Log N)***
- **SPACE COMPLEXITY** - ***O(1)***

### ✅ RECURSION APPROACH - *Using simple maths*
---------------------------------------------------------------
- **LOGIC** - 
   - Define a function `pow_recursive(x, n)` that returns a double
    - Base case:
        - If `n == 0`, return 1.0
    - If `n` is negative:
        - Return `1.0 / pow_recursive(x, -n)`
    - If `n` is even:
        - Compute `half = pow_recursive(x, n / 2)`
        - Return `half * half`
        - > Maths used - `x^n = (x^n/2)^2`
    - If `n` is odd:
        - Return `x * pow_recursive(x, n - 1)`
        - > Maths used - `x^n = x * x^n-1`


- **TIME COMPLEXITY** - ***O(Log N)***
- **SPACE COMPLEXITY** - ***Recursion call stack space***


<div style="display: flexbox; text-align: center; font-family: monospace;">
    <h1>THANK YOU!</h1>
</div>