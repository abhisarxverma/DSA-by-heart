# PROBLEM - Given an array, return the head of the Linked list that have the data of the array. 

## ✅ APPROACH
---------------

- **LOGIC** - *One by One Iterate over array and join into the linked list*
    - Start by creating a temporary node `(temp)` with dummy data `(-1)`. 
    - This serves as a placeholder to simplify insertion.
    - Use a mover pointer initialized to temp to track where new nodes should be added.
    - For each element in the array:
    - Create a new node with the current value.
    - Attach it to the next pointer of mover.
    - Move mover forward to the newly created node for the next insertion.
    - Once the iteration completes, the final linked list starts from temp's next, excluding the dummy node.
    - Using temp makes inserting nodes seamless, avoiding extra logic for handling the first node separately.

- **TIME COMPLEXITY** - ***O(Size of Array)***
- **SPACE COMPLEXITY** - ***O(1)***