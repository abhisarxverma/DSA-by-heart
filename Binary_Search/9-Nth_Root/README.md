# PROBLEM - Given the number and the integer 'n', find and return the nth root of that number if exists else return -1

### Example Input -   100, 2 | 343, 3 | 64, 4
### Example Output -     10  |   7    |   -1

## ✅ Brute Force Approach
- ***LOGIC***  -
    - To find the nth root of a number using linear search, we check each number from 0 to (number/n) + 1:
    - Compute the nth power of each number in this range.
    If the result matches the given number, return the current number (it is the nth root).
    - If the power is greater, stop the loop—the root was before this point.
    - If the power is smaller, continue checking further numbers.

- **TIME COMPLEXITY** - ***O(N)***
- **SPACE COMPLEXITY** - ***O(1)***

## ✅ Optimal Approach

- **LOGIC**  - 
    - To find the nth root of a number using binary search, we search in the range 0 to (number/n) + 1:
    - Get the mid value.
    - If mid^n == number, return mid (we found the exact nth root).
    - If mid^n > number, remove the right part (mid is too large).
    - If mid^n < number, remove the left part (mid is too small).
    - If no number satisfies mid^n == number, return -1 after the loop.

- **TIME COMPLEXITY** - ***O(Log N)***
- **SPACE COMPLEXITY** - ***O(1)***