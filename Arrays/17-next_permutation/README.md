# PROBLEM - Given an array, find the next permutation of the array.

### Input : {5, 2, 9, 7, 3}
### Output : {5, 3, 2, 7, 9}

## ✅ Optimal Approach

1. **Find the breakpoint:**  
   - Traverse the array **from right to left**.  
   - Locate the **first number** that is **smaller** than its next number.  
   - Store its index as the **breakpoint**, since the next permutation will change from here.

2. **Find the smallest greater number:**  
   - Search for the **smallest number greater than the breakpoint** in the right portion of the array.  
   - Swap this number with the breakpoint value to shift towards the next lexicographical order.

3. **Reverse the right part:**  
   - The segment after the breakpoint is initially in descending order.  
   - **Reverse it** to transform it into the smallest possible arrangement.

This ensures we generate the next permutation correctly while maintaining lexicographical order. 🚀

- TIME COMPLEXITY - O(3N) = O(N)
- SPACE COMPLEXITY - O(1)