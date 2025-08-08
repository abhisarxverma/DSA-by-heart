## PROBLEM - Given an integer n, find the total count of the good numbers of n number of digits, a good number is a number whose (0-indexed) even index digits are even and odd index digits are prime, leading zeros should also be counted as making a number.

### We will implement the solution first in the loop and then in the recursion.

### ✅ LOOP FORCE APPROACH - *Traditional for loop [ This will cause the Run Time Error]*
---------------------------------------------------------------------------------------------
- **LOGIC** - 
    - First get all the possible numbers that have n number of digits which will be 10 to the power n, cause there can be 10 digits only at one position and there are n positions to fill.
    - using a loop check each number if it satisfies the criteria of a good number


- **TIME COMPLEXITY** - ***O(N x 10^n) O(10^n) generating all possible numbers and O(n) for checking each digit in a combination bool is_good_number(const string& digits) ***
- **SPACE COMPLEXITY** - ***O(1)***


### ✅ RECURSION APPROACH - *Using depth first search*
---------------------------------------------------------------
- **LOGIC** - 
    - create a helper function which will do the recursion 
    - so there can only be 5 possible options for the even places and there can only be 4 possible options for the odd places
    - pass the function three parameters, index - integer, current - string, n - integer
    - put the base case that if the index becomes equal to n then this means we are out of the n length number so we will return 1 to add this number in the overall count
    - take count = 0 and also select the allowed_digits based on the index
    - then for each digit add in the count each time calling the function again for the furter indexes
    - at last return the count


- **TIME COMPLEXITY** - ***O(5^n/2 x 4^n/2) - we are going 5 level of depth for the even indexes and 4 level of depth for the odd indexes***
- **SPACE COMPLEXITY** - ***O(1)***

### ✅ MATHEMATICAL OPTIMAL APPROACH - *Using maths*
---------------------------------------------------------------
- **LOGIC** - 
    - We can get the answer without any kind of looping
    - count the number of even places in the number
    - count the nubmer of odd places in the number
    - for the even index places we have 5 possible options
    - for the odd index places we have 4 possible options
    - now just multiply 5 raised to power number of even places and 4 raised to power of number of odd places
    - we multiply cause we have to make combination of each even and each odd possible option


- **TIME COMPLEXITY** - ***O(1)***
- **SPACE COMPLEXITY** - ***O(1)***


<div style="display: flexbox; text-align: center; font-family: monospace;">
    <h1>THANK YOU!</h1>
</div>