# Lower Bound Implementation in C++ and Python

## Overview
This Code implements **Lower Bound**, a binary search variation that finds the **smallest index** of a target number in a sorted array.  
If the number doesn't exist, it returns the next larger number's index. If there is no larger number, it returns the **size of the array**, which is an **invalid index**.

## Understanding Lower Bound
The **Lower Bound** is the smallest index where `array[index] >= target`.  
- If the target exists, it returns the **first occurrence** of the number.
- If the target is missing, it returns the **next greater number’s index**.
- If no greater number exists, it returns the **array size**, meaning no valid index was found.

Example:
Given `{1, 5, 9, 10, 32, 55}` and searching for `6`, the next largest **is at index `2` (9).**

## Implementations
We provide **three implementations** of Lower Bound:

### 1️⃣ **Iterative Approach (Standard)**
    - Searches in log(n) time using binary search.
    - Tracks the smallest index that could be a valid lower bound.
    - Adjusts search space dynamically to ensure first occurrence.

### 2️⃣ **Iterative Approach (Optimized)**
    - Uses a conceptual shortcut where mid is kept in the search space if it might be the answer.
    - More efficient and concise, avoiding unnecessary storage.
    - Returns high, where low == high contains the final lower bound index.

### 3️⃣ **Recursive Approach**
    - Implements binary search recursively, reducing code complexity.
    - Ensures the smallest index for >= number is found correctly.