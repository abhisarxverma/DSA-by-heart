# PROBLEM - Given a Head Node, an integer number to insert and an integer place_number before which you have to insert the number insert the number and then return the head of the new linked list.

## ✅ APPROACH
---------------

- **LOGIC** - *Use Two Pointers*
    - Initialize front and back at head.
    - Traverse the list:
    - If front.data == target, insert new node between back and front.
    - Else, move back and front forward one step.
    - Target Not Found?
    - If traversal ends without finding the value, no insertion is done.

- **TIME COMPLEXITY** - ***O(Size of Linked List)***
- **SPACE COMPLEXITY** - ***O(1)***