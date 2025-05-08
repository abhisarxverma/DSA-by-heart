# Ceil & Floor Implementation (Binary Search)

## Overview
This Program folder implements **Ceil** and **Floor** functions using **binary search** to efficiently find numerical bounds in a sorted array.

### **Ceil Function**  
Finds the **smallest number ≥ target** in a sorted array.  
If the number **exists**, it returns the number.  
If it doesn’t, it returns the **next greater number**.  
If no number is greater, it returns **the size of the array**.

### **Floor Function**  
Finds the **largest number ≤ target** in a sorted array.  
If the number **exists**, it returns the number.  
If it doesn’t, it returns the **next smaller number**.  
If no number is smaller, it returns **-1**.

---

## Understanding Ceil & Floor

### **Ceil (`ceil(array, number)`)**
- If `number` exists → **Returns itself**.
- If `number` is missing → **Returns next greater**.
- If no greater number exists → **Returns array size**.

**Example:**
```python
array = [1, 5, 6, 10, 50, 100]
ceil(array, 7)  # Returns 10 (next greater)
ceil(array, 100)  # Returns 100 (itself)
ceil(array, 101)  # Returns array size (invalid)
```

### **Floor(`floor(array, number)`)**
- If `number` exists → ***Returns itself***.
- If `number` is missing → ***Returns next smaller***.
- If no smaller `number` exists → ***Returns -1***.

**Example:**
```python
array = [1, 5, 6, 10, 50, 100]
floor(array, 7)  # Returns 6 (next smaller)
floor(array, 100)  # Returns 100 (itself)
floor(array, 0)  # Returns -1 (invalid)
```