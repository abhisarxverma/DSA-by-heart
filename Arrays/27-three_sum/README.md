# PROBLEM - Given an array of integers, find the and return all the triplets that have the sum 0

### EXAMPLE INPUT - 3, 5, -1, 5, -10, -8, 5, 0
### EXAMPLE OUTPUT - [3, 5, -8], [5, -10, 5]


## ✅ Brute Approach

- LOGIC -
    1. **Use a Set**  
    - To ensure **unique triplets**, store each valid triplet in a set after sorting.
    
    2. **Nested Loop Iteration**
    - Iterate over the array three times (`O(N³)`) to check **all possible triplets**.
    - If their sum equals **zero**, store the triplet.

    3. **Sorting the Triplets**
    - Before inserting into the set, sort the triplet to prevent duplicate variations (e.g., `[1, -1, 0]` vs. `[0, -1, 1]`).

    4. **Extract Unique Triplets**
    - Convert the set into a vector and return it.

- **TIME COMPLEXITY** - O(N^3 + LogM) = O(N^3) *Due to three nested loops*
- **SPACE COMPLEXITY**- O(N^3) *Worst case : Set will store all the triplets from the array*

## ✅ Better Approach

- LOGIC -
    1. **Iterate Over the Array** (`i` loop)
    - This represents the first element of the triplet.

    2. **Use a Set to Track Visited Numbers** (`j` loop)
    - Before starting the second loop, **initialize a set** to store numbers seen so far.

    3. **Check for the Complement in the Set (`k` loop)**
    - For each element `array[k]`, compute **`target = 0 - (array[j] + array[k])`**.
    - If this **`target` exists in the set**, we found a valid triplet.

    4. **Store the Triplet (Avoid Duplicates)**
    - Sort the triplet before storing it in a result structure to ensure uniqueness.

- **TIME COMPLEXITY** - O(N²) *(Improved from O(N³))*
- **SPACE COMPLEXITY** - O(N) *Extra Space (For storing visited elements in a set)*

## ✅ Optimal Approach

- LOGIC - 
    1. **Sort the Array**  
    - Sorting simplifies finding triplets efficiently.

    2. **Use Three Pointers**
    - `start` pointer at **beginning** of the array.
    - `end` pointer at **end** of the array.
    - `middle` pointer at **next to `start`**.

    3. **Adjust Pointers Based on Sum**
    - If the sum of three numbers is **less than zero**, move `middle` **right** to increase the sum.
    - If the sum is **greater than zero**, move `end` **left** to decrease the sum.
    - If the sum is **zero**, store the triplet and **skip duplicate values** to avoid redundant results.

### **Why is This Optimal?**
- **TIME COMPLEXITY** - O(N²) *Complexity(Improved from O(N³) brute force)*.  
- **SPACE COMPLEXITY** - O(1) *Efficiently manages duplicates using the sorted array* 
