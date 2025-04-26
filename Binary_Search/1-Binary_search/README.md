# 🔍 Binary Search

### 📌 What is Binary Search?
Binary Search is a fast way to find an element in a **sorted** array. Instead of checking each item one by one, it **divides the search space in half**, making the process much faster (**O(log N)** time complexity).

### 🚀 How it Works:
1. **Start with the middle element.**
2. If it's the number you're looking for (**k**) → ✅ **Found!**
3. If **k** is **smaller**, search in the **left half**.
4. If **k** is **greater**, search in the **right half**.
5. Keep repeating until **1 element remains** or **k is found**.

### 🔎 Why Binary Search is Fast:
Instead of checking **every number**, it **eliminates half of the data** in every step. This makes searching **efficient**, especially for large datasets.

### ✨ Key Rule:
**Binary Search works ONLY on sorted data!** If the array isn’t sorted, it **won’t work**.

This method is widely used in real-world applications like **database lookups, search engines, and games**. 🚀  

***I have put both the iterative and recursive implementation of Binary Search in both Python And C++. Cheers!***
