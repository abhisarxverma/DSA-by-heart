# PROBLEM - Given two head nodes of the two linked list, find and the intersection node if any else return None

### ✅ BRUTE FORCE APPROACH - *Double Looping*
---------------------------------------------
- **LOGIC** - *Double Iteration*
    - Traverse any of the two linked list
    - And for every iteration, traverse the other linked list to find the same node
    - If found return the node else return None

- **TIME COMPLEXITY** - ***O(NxM) Double Iteration***
- **SPACE COMPLEXITY** - ***O(1)***

### ✅ BETTER APPROACH - *Using Hashset*
---------------------------------------------------------------
- **LOGIC** - *Using hashset*
    - Take an unordered set [It uses hashing for O(1) lookup]
    - Traverse any of the two linked list
    - And in every iteration, insert the node into the set
    - then traverse the second linked list and check for the node in the set
    - return node if found else return None at last

- **TIME COMPLEXITY** - ***O(N+M) N to put into the hashset and M to check for intersection***
- **SPACE COMPLEXITY** - ***O(N) hashset***

### ✅ OPTIMAL APPROACH - *Two Pointer Continuous Looping*
---------------------------------------------------------------
- **LOGIC** - *Continuous Looping*
    - Take two node pointer variables which will be the mover of the both of the linked list
    - Run a while loop till both the movers become equal
    - in the loop move both the movers to their next
    - then check if both the movers are equal return any of the mover
    - the trick is here
    - if any of the mover becomes null, make that mover head node of the other linked list
    - In this way we are comparing every node in the two linked lists
    - If you think how will the loop end if there is no intersection in both linked list
    - The loop will end when both the movers will become null which will happen for sure if the intersection is not there


- **TIME COMPLEXITY** - ***O(N + M)***
- **SPACE COMPLEXITY** - ***O(1)***


<div style="display: flexbox; text-align: center; font-family: monospace;">
    <h1>THANK YOU!</h1>
</div>