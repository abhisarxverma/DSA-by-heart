# PROBLEM - Given a Head node, delete the last node and return the new head.
 

## ✅ APPROACH
---------------
- **LOGIC** - 
    - To delete the last node we will have to go to the last second node
    - When reached the last second node, save the last node in another variable to free later
    - make the last second's node's next pointer to nullptr
    - Free the last node saved in another variable
    - return the `head`

- **TIME COMPLEXITY** - ***O(Size of the array)***
- **SPACE COMPLEXITY** - ***O(1)***