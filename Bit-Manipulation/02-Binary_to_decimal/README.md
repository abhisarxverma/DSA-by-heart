### 🧩 Problem  
We want to **convert a binary number (base 2)** into its **decimal representation (base 10)**.  

---

### ⚙️ Approach 1: Iterative  
- Reverse the binary string to process from least significant bit.  
- Start with position = 1 (which represents \(2^0\)).  
- For each bit:
  - If it’s `'1'`, add the current position value to the decimal result.  
  - Multiply position by 2 for the next bit.  
👉 Step-by-step accumulation of powers of 2.  

---

### 🔄 Approach 2: Recursive  
- Process the string from left to right.  
- At each index:
  - Convert the character to a digit (`'0'` or `'1'`).  
  - Calculate its weight as \(2^{(length - index - 1)}\).  
  - Add it if the bit is 1, then recurse to the next index.  
👉 Elegant divide-and-conquer using function calls.  

---

### ✨ Summary  
Both methods achieve the same goal: **binary → decimal**.  
- Iterative = loop-based accumulation 🏃  
- Recursive = function-based breakdown 🧠  
