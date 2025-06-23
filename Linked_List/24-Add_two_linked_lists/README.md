## PROBLEM - Given two linked lists, return the head of the new linked list that will be formed if we add the numbers in both the linked list like we do addition.


### ✅ BRUTE FORCE APPROACH - *Reversing Linked list and adding like we do in normal addition*
-------------------------------------------------------------------------------------------------
- **LOGIC** - *Reversing the linked list to add, like we do in normal addition backwards*

    - Reverse the two linked lists
    - Take two node pointer varaibles to traverse both of them simultaneously
    - Take a carry integer variable to keep track of the carry that we need to add to the next
    - Take a dummy node pointer variable that will be our answer linked list and also take a res_mover to move forward and add the answers to the answer linked list
    - Start traversing till both of the movers are not null, take a add integer in the loop
    - Add the carry to the add
    - Then after checking if the movers are not null add the mover's data to the add and move them forward
    - If you find that the add is less than 10, then simply we will make the carry to 0 cause we have added the carry in this one without overflow
    - and we will add a new node after res_mover with data as the current add in the loop and then we will move the res_mover to it's forward
    - And if you find the add is more than or equal to the 10 then we have to update the carry to 1 cause we need to add this to upcoming additions
    - Then we will make add a new node after the res_mover with the add % 10 because, we have already passed the 1 to the carry forward so we have to add in the new node what's left
    - After the loop gets over if we are left with the carry then this means that we have to add a new node because of the carry overflow
    - We will add a new node after the res_mover with the data of the carry
    - Also we have to remember to make the two linked list same as before, as we have reversed, changing the input given to us is not a good practice in competetive programming
    - So will reverse again the two heads
    - Then we also have to free the space of the dummy node 
    - so we will take our answer in a new node pointer variable
    - We will free the dummy node 
    - Also we have calculated the sum of the two linked list while iterating them in reversed condition that's why our answer is also reversed
    - so we have to return the reversed version of our answer linked list.

- **TIME COMPLEXITY** - ***O(5N) - Two N's to reverse the heads, N to traverse and find the addition, N to reverse the answer linked list, Two N's to reverse the two input heads again.***
- **SPACE COMPLEXITY** - ***O(N) Because we are using recursive reversal, can be O(1) if we use the iterative reversal***

### ✅ OPTIMAL APPROACH - *Recursion*
---------------------------------------------------------------
- **LOGIC** - *Recursion*
    - Reverse both input lists
    - Since the numbers are stored in forward order (most significant digit at the head), we reverse both lists to simplify addition starting from the least significant digit (like traditional arithmetic).
    - Perform recursive addition
    - Traverse both reversed lists using recursion:
    - At each step, add corresponding digits along with any carry.
    - Create a new node for sum % 10.
    - Recurse with the next nodes and sum / 10 as carry.
    - Base case- stop when both lists are nul and carry is 0.
    - Build the result list in reverse order
    - Each recursive return stacks a node on top of the previous sum.
    - The result is built in reverse (least significant to most significant).
    - Reverse the result list
    - To restore the correct forward order, reverse the summed list once more before returning.

- **TIME COMPLEXITY** - ***O(N+M) - O(N+M) for reversing + O(Max(N,M)) for adding + O(N+M) for reversing again.***
- **SPACE COMPLEXITY** - ***O(Max(N, M)) Recursion call stack***


<div style="display: flexbox; text-align: center; font-family: monospace;">
    <h1>THANK YOU!</h1>
</div>