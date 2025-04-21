# PROBLEM - Given an array of intergers and an integer k, give the total number of subarrays that give the sum k.


### EXAMPLE INPUT - 5, 2, 7, -2, 9 
### EXAMPLE OUTPUT - 3

## ✅ Brute Approach

- LOGIC - Take a variable count, Loop over every element, loop over every element on the right and add it while checking if the sum
is equal to k if yes increment the count.

- TIME COMPLEXITY - O(N^2)
- SPACE COMPLEXITY - O(1)

## ✅ Optimal Approach

- LOGIC -
    1. Use a **HashMap** to store cumulative sums encountered while iterating.
    2. While iterating:
    - Add each number to a **running sum**.
    - Check if `(current sum - k)` exists in the HashMap.
        - If yes, it means removing certain previous elements results in a subarray sum equal to `k`.
        - Increase the count based on the frequency of `(current sum - k)`.
    - Store the running sum and its frequency in the HashMap.

    ### **Concept:**
    - If at any point, the sum exceeds `k`, but we have recorded past sums that allow us to subtract and get `k`, then that past occurrence enables a valid subarray.
    - The HashMap keeps track of how many times each sum occurs, ensuring we efficiently find all valid subarrays.

- TIME COMPLEXITY - O(N)
- SPACE COMPLEXITY - O(N) hashmap