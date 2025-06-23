# PROBLEM - Given the head node of a linked list having integers as datatype, return the new linked list that will be formed if 1 is added to the number forming after combining the data of the linked list.


### ✅ BRUTE FORCE APPROACH - *Reversing Linked list and adding like we do in normal addition*
-------------------------------------------------------------------------------------------------
**LOGIC** - *Reversing Linked List*
    - Reverse the linked list to process digits from least to most significant.
    - Initialize two pointers: – mover to traverse the list – prev to track the last non-null node (for possible carry node insertion)
    - Start with carry = 1 and loop through the list:
    - Add the carry to mover->data
    - If the sum is less than 10, update the node and break (no more carry)
    - Else, set node to 0, keep carry = 1, and move forward
    - If carry remains after the loop, append a new node with value 1 using prev.
    - Reverse the list again and return the updated head.

**TIME COMPLEXITY** - ***O(3N) - O(N) to reverse + O(N) to traverse + O(N) to reverse again to return***
**SPACE COMPLEXITY** - ***O(N) Because we are using recursive reversal, can be O(1) if we use the iterative reversal***

### ✅ OPTIMAL APPROACH - *Recursion*
---------------------------------------------------------------
**LOGIC** - *Recursion*
    - Use recursion to reach the last node (least significant digit).
    - Add 1 at the base case, and propagate carry back through the stack:
    - If the sum is less than 10, update the node and return 0 (no carry).
    - If the sum is 10, set the node to 0 and return 1 (carry over).
    - In the main function, call the recursive helper:
    - If it returns 0, you're done—return the head.
    - If it returns 1, insert a new node with value 1 at the head (carry overflow).
    - Return the updated head of the list.

**TIME COMPLEXITY** - ***O(N) Recursive calls for every node in linked list***
**SPACE COMPLEXITY** - ***O(N) Recursive call stacks***


<div style="display: flexbox; text-align: center; font-family: monospace;">
    <h1>THANK YOU!</h1>
</div>