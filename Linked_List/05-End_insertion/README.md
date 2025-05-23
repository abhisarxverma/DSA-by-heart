## PROBLEM - Given a Head Node and an integer to insert to the end of the linked list, insert the number at end and return the head of the new linked list.

### ✅ APPROACH
---------------
- **LOGIC** - 
    - To insert a new node at the end of the linked list, we will go to the end node.
    - But before that check if the `head` passed is null, if yes, this means that the linked list is empty, return `null`.
    - Take a `mover` pointer variable with the value `head`.
    - move the `mover` forward, till the next node of the `mover` becomes null.
    - Now the `mover` is the last node of the linked list.
    - Make a new node with the data equal to the number given, and make it next to the `mover`
    - return the `head`.

- **TIME COMPLEXITY** - ***O(Size of Array)***
- **SPACE COMPLEXITY** - ***O(1)***