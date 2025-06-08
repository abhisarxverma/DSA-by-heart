# PROBLEM - Given the head node of the linkd list, remove the middle node and return the head of the new linked list.


### ✅ BRUTE FORCE APPROACH - *Counting the length*
---------------------------------------------
- **LOGIC** - *Counting the length*
    - First count the length of the linked list
    - Then go one node before the "total length / 2" and delete that

- **TIME COMPLEXITY** - ***O(N + N/2) N to count, N/2 to delete***
- **SPACE COMPLEXITY** - ***O(1)***

### ✅ BETTER APPROACH - *The middle node moves one step when the length moves two steps*
---------------------------------------------------------------
- **LOGIC** - *The middle node moves one step when the length moves two steps*
    - Take a length counter
    - Take a prev node pointer
    - Take a mover node pointer
    - Move the mover while the mover does not become null
    - And in the loop, evertime the length becomes even, just move the prev pointer
    - At end of the loop, you will have your prev at the one node before the middle
    - Just delete that the normal process and return the head.

- **TIME COMPLEXITY** - ***O(N/2)***
- **SPACE COMPLEXITY** - ***O(1)***

### ✅ OPTIMAL APPROACH - *TORTOISE HARE ALGORITHM*
---------------------------------------------------------------
- **LOGIC** - *tortoise hare algorithm*
    - Logic here is same that the middle moves one step when the length moves two step
    - but the implementation will be more simple and startight forward
    - take two node pointer variables fast and slow
    - run a while loop till the fast and the fast's next is not null
    - and in the loop move the fast two step and the slow one step
    - When the loop will end the slow is the middle node
    - but to remove the middle node we have to go one node before the middle
    - so we will also maintain a prev node pointer that will save the previous middle if the middle changes
    - and then we will remove the middle with normal procedure and then return the head

- **TIME COMPLEXITY** - ***O(N/2)***
- **SPACE COMPLEXITY** - ***O(1)***

<div style="display: flexbox; text-align: center; font-family: monospace;">
    <h1>THANK YOU!</h1>
</div>