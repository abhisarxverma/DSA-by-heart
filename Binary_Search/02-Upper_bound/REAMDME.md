# Upper Bound Implementation in C++ And Python

## Overview
This Code implements **Upper Bound**, a variant of binary search that finds the next largest number in a sorted array.  
If no larger number exists, it returns the array's size.

## Understanding Upper Bound
The **Upper Bound** is the smallest number **strictly greater** than the target in a sorted array. If the target exists in the array, the function **skips it** and finds the next largest element.

Example:
Given `{1, 5, 9, 10, 32, 55}` and searching for `6`, the next largest is `9`.

## Implementations
We provide **three implementations** of Upper Bound:

### 1️⃣ **Iterative Approach (Standard)**
    - Searches in log(n) time using binary search.
    - Keeps track of the smallest number greater than the target.
    - If no greater number exists, returns array.size().

### 2️⃣ **Iterative Approach (Optimized)**
    - Uses a shortcut where instead of eliminating mid, it keeps mid in search space.
    - More concise and avoids unnecessary storage of intermediate results.
    - Returns high, where low == high contains the answer.

### 3️⃣ **Recursive Approach**
    - Uses recursion instead of a loop.
    - Base condition ensures the correct exit.
    - Divides search space and processes only required sections, following binary search logic.
