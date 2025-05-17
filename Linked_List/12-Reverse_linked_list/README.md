# PROBLEM - Given a Head Node of the linked list, reverse the linked list and return the new head.

### ✅ BRUTE FORCE 1 APPROACH - *Using Vector*
-------------------------------------------------

- **LOGIC** - *Using a vector*
    - Take a vector 
    - Traverse the whole linked list and add the data in the vector
    - Now loop over the vector in the backward order and update the data sequence in the linked list
    - return the head

- **TIME COMPLEXITY** - ***O(N)***
- **SPACE COMPLEXITY** - ***O(N) Vector space***


### ✅ BRUTE FORCE 2 APPROACH - *Using Stack*
----------------------------------------------
- **LOGIC** - *Using Stack*
    - Take a stack
    - Travese the linked list and put the data in the stack
    - Travese the linked list again but this time update the data by popping from data from the stack everytime
    - Cause stack will give you the data entered last, so the last data of the linked list will be added first
    - return the head

- **TIME COMPLEXITY** - ***O(N)***
- **SPACE COMPLEXITY** - ***O(N) Stack***


*For using both the brute force, we have to know beforehand what type of the data is in the linked list, cause while initializing the vector or the stack or the queue, we have to predefine the type. For here I assumed that the linked list will have the integer data, but that can be of any type.*



### ✅ BETTER APPROACH - *Changing links using three pointers*
---------------------------------------------------------------
- **LOGIC** - Three Pointer Approach
    - Take three Node pointers - front, back and the mover
    - Initialize the front and the back node pointer with the nullptr
    - Initialize the mover node pointer with the head node
    - Run a while loop till the mover is not nullptr
    - And in the loop, we will do a simple thing, we will just take the one step back node and make it the current mover's next node
    - But the catch is that if we directly, make the current mover's next to the back, then how will we move forward?
    - So we will first save the next node of the mover in the front node pointer variable
    - And after saving, we will make the mover's next node the back node
    - Then we will make the back node, the current mover, cause this mover will be the back node for the next node
    - Then at last we will move the mover to the front node, which we saved earlier for this point.
    - When the loop ends, means the mover becomes nullptr, in the last iteration the mover (last node) was saved in the back
    - Now the back will be the head of the reversed linked list.

- **TIME COMPLEXITY** - ***O(N)***
- **SPACE COMPLEXITY** - ***O(1)***


### ✅ OPTIMAL APPROACH - *Changing links using the Recursion*
---------------------------------------------------------------
- **LOGIC** - *USING THE RECURSION*
    - Base Case: If the list is empty (`head == nullptr)` or only has one node (`head->next == nullptr`), return the original list.
    - Recursive Case:
        Recursively call the function on the rest of the list (`head->next`).
        Move the current node two steps forward (`head = head->next->next`).
        Set the next pointer of the current node to `nullptr` to break the link.
        Return the reversed list starting from the new head (`reversed_head`).

- **TIME COMPLEXITY** - ***O(N)***
- **SPACE COMPLEXITY** - ***O(N) Recursion call stack***