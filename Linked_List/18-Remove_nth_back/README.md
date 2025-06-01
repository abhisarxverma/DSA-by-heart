# PROBLEM - Given the head node of the linked list and an integer n, remove the nth node from the back and return the head of the result linked list

### ✅ BRUTE FORCE APPROACH - *Getting the Length of Linked list*
---------------------------------------------
- **LOGIC** - *Getting the length of the linked list*
    - Take a counter to 0
    - traverse the linked list and update the counter every time
    - now we got the length of the linked list
    - now we have to remove the nth from back, so we have to go to the `total - n - 1`
    - one before to remove the node and join it's next.
    - using the mover we will go to `total - n - 1` node
    - when we got there we will simply make the current node's next the current node's next's next
    - And we will free the current node's next
    - and return the head

- **TIME COMPLEXITY** - ***O(2N) First loop to get the length and the second to remove the node***
- **SPACE COMPLEXITY** - ***O(1)***

### ✅ OPTIMAL APPROACH - *Clever Approach*
---------------------------------------------------------------
- **LOGIC** - *Clever Approach*
    - Take a node pointer variable "front" and initialize that with the head
    - take the front to the nth from the front by moving it n-1 times
    - then take another node pointer variable "back" and initialize that with the head
    - now we have the back at head and the front at the nth from the front
    - now move both the nodes simultaneously until the the front's next becomes null
    - and when that happens the back will be at one node before the node to delete

- **TIME COMPLEXITY** - ***O(N)***
- **SPACE COMPLEXITY** - ***O(1)***

<div style="display: flexbox; text-align: center; font-family: monospace;">
    <h1>THANK YOU!</h1>
</div>