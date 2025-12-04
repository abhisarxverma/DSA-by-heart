### 🧩 Problem 

We want to **convert a decimal number (base 10)** into its **binary representation (base 2)**.  

---

### ⚙️ Approach 1: Iterative  
- Keep dividing the number by 2.  
- Collect the remainders (`n % 2`) as binary digits.  
- Reverse the collected digits to get the final binary string.  
👉 Works like repeatedly chopping the number until it hits zero.  

---

### 🔄 Approach 2: Recursive  
- Break the number down by dividing it by 2.  
- Recursively build the binary string from the smaller subproblem.  
- Append the remainder (`n % 2`) at each step.  
👉 Elegant, but relies on function calls instead of loops.  

---

### ✨ Summary  
Both methods achieve the same goal: **decimal → binary**.  
- Iterative = step-by-step loop 🏃  
- Recursive = divide & conquer 🧠  

