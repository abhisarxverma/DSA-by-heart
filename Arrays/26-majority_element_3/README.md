# PROBLEM - Given an array, find the number which appears more than one-third of the size of the array


### EXAMPLE INPUT - 2, 5, 2, 9, 2, 1
### EXAMPLE OUTPUT - 2

## ✅ Brute Approach

- LOGIC - Loop over every element and then loop over the array again to get the count of the number of the outer loop
if the count is greater than the one-third of the array then return else pass. and if the majority element is not there
return -1

- TIME COMPLEXITY - O(N^2)
- SPACE COMPLEXITY - O(1)

## ✅ Better Approach

- LOGIC - Use a hashmap as a count storer, while iterating update the count in the hashmap and if the count
is greater than one-third of the size of the array return the number

- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(N) hashmap

## ✅ Optimal Approach

- LOGIC - 

    ### **Logic Overview**

    - **Key Observation:** In an array, there can be at most **2 elements** that appear more than **1/3** of the total size.
    - **Modified Boyer-Moore Voting Algorithm:**  
    - Instead of tracking **one** candidate, we track **two**.
    - Maintain two variables for potential majority elements.
    - Increment their counts when encountered, decrement when encountering different elements.
    - At the end, these two variables should hold the **potential majority elements**.

    ### **Step-by-Step Algorithm**
    
    1. **Initialize two candidate variables** (`num1` and `num2`) and their respective counters.
    2. **Iterate through the array:**
    - If the current element matches `num1`, increment `count1`.
    - Else if it matches `num2`, increment `count2`.
    - If `count1` is zero, assign the current element to `num1` and set `count1 = 1`.
    - Else if `count2` is zero, assign the current element to `num2` and set `count2 = 1`.
    - Otherwise, decrement both counts (`count1--`, `count2--`).
    3. **Second pass:**  
    - Validate whether `num1` and `num2` actually appear more than `n/3` times.

- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(1)